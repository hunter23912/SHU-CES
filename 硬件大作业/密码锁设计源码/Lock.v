`include "constant.v"
`include "Watcher.v"

// 密码锁
module Lock (
    input  wire                      clk,
    input  wire                      rst_n,
    input  wire [               3:0] controlSignal,
    input  wire [   `INPUT_BITS-1:0] inputNumber,
    output wire [`PASSWORD_BITS-1:0] display
);

  localparam `INDEX_TYPE InputBufferSlots = (`PASSWORD_LENGTH / `INPUT_WIDTH);
  localparam `PASSWORD_TYPE InputMask = ((1 << `INPUT_BITS) - 1);

  localparam `STATE_TYPE StateSet = 3'h0;  // 设置密码模式
  localparam `STATE_TYPE StateInput = 3'h1;  // 输入一块数字
  localparam `STATE_TYPE StateReset = 3'h2;  // 重置输入
  localparam `STATE_TYPE StateUnlock = 3'h3;  // 解锁模式
  localparam `STATE_TYPE StateUnlockInputFininsh = 3'h4;  // 解锁输入结束状态
  localparam `STATE_TYPE StateUnlockCorrect = 3'h5;  // 解锁正确状态
  localparam `STATE_TYPE StateUnlockIncorrect = 3'h6;  // 解锁错误状态
  localparam `STATE_TYPE StateNIL = 3'h7;  //空状态

  `STATE_TYPE state;
  // 状态栈
  `STATE_TYPE stateStack;

  `PASSWORD_TYPE inputBuffer, password, displayBuffer;
  `INDEX_TYPE inputBufferIndex;

  assign display = displayBuffer;

  // 临时变量
  reg [4:0] shift;
  `PASSWORD_TYPE maskForEdit, patchedNumber;
  reg onDisplayMessage;
  `COUNTER_TYPE displayMessageClockCounter, onEditFlashCounter;

  // 边沿检测
  /* verilator lint_off UNUSEDSIGNAL */
  wire modeSettingWirePos, modeSettingWireNeg;
  Watcher modeSettingWireWatcher (
      .clk   (clk),
      .rst_n (rst_n),
      .signal(controlSignal[3]),
      .pos   (modeSettingWirePos),
      .neg   (modeSettingWireNeg)
  );
  wire inputNextSignalPos, inputNextSignalNeg;
  Watcher inputNextSignalWatcher (
      .clk   (clk),
      .rst_n (rst_n),
      .signal(controlSignal[2]),
      .pos   (inputNextSignalPos),
      .neg   (inputNextSignalNeg)
  );
  wire resetSignalPos, resetSignalNeg;
  Watcher resetSignalWatcher (
      .clk   (clk),
      .rst_n (rst_n),
      .signal (controlSignal[1]),
      .pos   (resetSignalPos),
      .neg   (resetSignalNeg)
  );
  wire passwordInputFinishSignalPos, passwordInputFinishSignalNeg;
  Watcher passwordInputFinishSignalWatcher (
      .clk   (clk),
      .rst_n (rst_n),
      .signal(controlSignal[0]),
      .pos   (passwordInputFinishSignalPos),
      .neg   (passwordInputFinishSignalNeg)
  );
  /* verilator lint_off UNUSEDSIGNAL */

  always @(posedge clk, negedge rst_n) begin

    if (!rst_n) begin
      state                      = StateSet;
      stateStack                 = StateSet;

      inputBuffer                = 0;
      inputBufferIndex           = InputBufferSlots - 1;

      password                   = 0;

      onDisplayMessage           = 0;
      displayMessageClockCounter = 0;

      onEditFlashCounter         = 0;

      displayBuffer              = 0;
    end else begin
      case (state)
        StateSet: begin
          if (modeSettingWirePos) begin
            password         = inputBuffer;
            inputBuffer      = 0;
            inputBufferIndex = InputBufferSlots - 1;


            state            = StateUnlock;
          end else if (inputNextSignalPos || inputNextSignalNeg) begin
            stateStack = state;

            state      = StateInput;
          end else if (resetSignalPos) begin
            stateStack = state;

            state      = StateReset;
          end
        end
        StateInput: begin
          begin
            inputBuffer = ((inputBuffer | maskForEdit) ^ maskForEdit) | patchedNumber;
            inputBufferIndex = inputBufferIndex == 0 ? InputBufferSlots - 1 : inputBufferIndex - 1;
          end
          if (stateStack == StateSet) begin
            state = StateSet;
          end else if (stateStack == StateUnlock) begin
            state = StateUnlock;
          end
          stateStack = StateNIL;
        end
        StateReset: begin
          inputBuffer      = 0;
          inputBufferIndex = InputBufferSlots - 1;

          if (stateStack == StateSet) begin
            state = StateSet;
          end else if (stateStack == StateUnlock) begin
            state = StateUnlock;
          end
          stateStack = StateNIL;
        end
        StateUnlock: begin
          if (modeSettingWireNeg) begin
            inputBuffer      = password;
            inputBufferIndex = InputBufferSlots - 1;

            state            = StateSet;
          end else if (inputNextSignalPos || inputNextSignalNeg) begin
            stateStack = state;

            state      = StateInput;
          end else if (resetSignalPos) begin
            stateStack = state;

            state      = StateReset;
          end else if (passwordInputFinishSignalPos) begin
            state = StateUnlockInputFininsh;
          end
        end
        StateUnlockInputFininsh: begin
          if (inputBuffer == password) begin
            displayMessageClockCounter = `CLOCKS_PER_SEC;

            state                      = StateUnlockCorrect;
          end else begin
            displayMessageClockCounter = 3 * `CLOCKS_PER_SEC;

            state                      = StateUnlockIncorrect;
          end
          onDisplayMessage = 1;
        end
        StateUnlockCorrect: begin
          if (displayMessageClockCounter % (2 * `CLOCKS_PER_FLASH) == 0) begin
            displayBuffer = `MESSAGE_CORRECT;
          end else if (displayMessageClockCounter % `CLOCKS_PER_FLASH == 0) begin
            displayBuffer = 0;
          end

          if (displayMessageClockCounter == 0) begin
            onDisplayMessage = 0;

            state            = StateUnlock;
          end else begin
            displayMessageClockCounter = displayMessageClockCounter - 1;
          end
        end
        StateUnlockIncorrect: begin
          if (displayMessageClockCounter % (2 * `CLOCKS_PER_FLASH) == 0) begin
            displayBuffer = `MESSAGE_INCORRECT;
          end else if (displayMessageClockCounter % `CLOCKS_PER_FLASH == 0) begin
            displayBuffer = 0;
          end

          if (displayMessageClockCounter == 0) begin
            onDisplayMessage = 0;

            state            = StateUnlock;
          end else begin
            displayMessageClockCounter = displayMessageClockCounter - 1;
          end
        end
        default: begin
        end
      endcase

      // 计算输入偏移量与输入遮罩
      begin
        shift = inputBufferIndex * `INPUT_BITS;
        begin
          patchedNumber                     = 0;
          patchedNumber[shift+:`INPUT_BITS] = inputNumber;
        end
      end
      maskForEdit = InputMask << shift;

      //闪烁显示输入遮罩
      if (!onDisplayMessage) begin
        displayBuffer = inputBuffer;

        // 闪烁显示当前输入的位
        if (!onDisplayMessage) begin
          onEditFlashCounter = onEditFlashCounter+1 == 2*`CLOCKS_PER_FLASH?0:onEditFlashCounter+1;

          displayBuffer = displayBuffer & (~maskForEdit);
          if (onEditFlashCounter < `CLOCKS_PER_FLASH) begin
            displayBuffer = displayBuffer | patchedNumber;
          end
        end
        // 只显示最后一次输入的几位
        if (state == StateUnlock || stateStack == StateUnlock) begin
          displayBuffer = displayBuffer & (maskForEdit);
        end
      end
    end
  end
endmodule
