`default_nettype none

/* verilator lint_off BLKSEQ */

`include "Lock.v"

module tb_Lock ();
  reg clk_tb;
  reg rst_n_tb;
  reg modeSettingWire_tb;
  reg inputNextSignal_tb;
  reg resetSignal_tb;
  reg passwordInputFinishSignal_tb;
  `INPUT_TYPE inputNumber_tb;

  /* verilator lint_off UNUSEDSIGNAL */
  wire [`PASSWORD_BITS-1:0] display_tb;
  /* verilator lint_off UNUSEDSIGNAL */

  Lock lock (
         .clk(clk_tb),
         .rst_n(rst_n_tb),
         .controlSignal({modeSettingWire_tb,
                         inputNextSignal_tb,
                         resetSignal_tb,
                         passwordInputFinishSignal_tb}),
         .inputNumber(inputNumber_tb),
         .display(display_tb)
       );

  localparam integer NsPerClk = 1000000;
  localparam integer NsPerOp = 1000 * NsPerClk;
  localparam integer InputSignalDelay = 100*NsPerClk;
  always #(NsPerClk / 2) clk_tb = ~clk_tb;


  // 二位随机数发生器
`define RANDOM_2_8 ($urandom_range(0, 9)[7:0]*10+$urandom_range(0, 9)[7:0])

  `PASSWORD_TYPE randomPassword;
  `INDEX_TYPE i;


  initial
  begin
    $dumpfile("Lock.vcd");
    $dumpvars(0, tb_Lock);
  end

  initial
  begin
    // 生成随机密码
    randomPassword = 0;
    for (i = 0; i < `PASSWORD_LENGTH; i = i + 1)
    fork
      randomPassword = (randomPassword << 4) + $urandom_range(0, 9)[`PASSWORD_BITS-1:0];
    join

    // 初始化
    fork
      clk_tb=0;
      rst_n_tb = 1'b0;
    join
    #NsPerOp;

    // 开始执行
    fork
      rst_n_tb = 1'b1;
    join
    #NsPerOp;

    // 设置
    // 输入密码
    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b1;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b0;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b1;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b0;
    join
    #NsPerOp;

    // 重置密码
    fork
      resetSignal_tb = 1'b1;
    join
    #NsPerOp;

    // 输入密码
    fork
      resetSignal_tb     = 1'b0;
      inputNumber_tb     = randomPassword[23:16];
      inputNextSignal_tb = #InputSignalDelay 1'b1;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = randomPassword[15:8];
      inputNextSignal_tb = #InputSignalDelay 1'b0;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = randomPassword[7:0];
      inputNextSignal_tb = #InputSignalDelay 1'b1;
    join
    #NsPerOp;

    // 解锁
    fork
      modeSettingWire_tb = 1'b1;
    join
    #NsPerOp;

    // 输入密码
    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b0;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b1;
    join
    #NsPerOp;

    fork
      inputNumber_tb     = `RANDOM_2_8;
      inputNextSignal_tb = #InputSignalDelay 1'b0;
    join
    #NsPerOp;

    #NsPerOp;

    // 检查错误密码
    fork
      passwordInputFinishSignal_tb = 1'b1;
    join
    #(3.5 * NsPerClk * `CLOCKS_PER_SEC);
    #NsPerOp

     // 输入密码
     fork
       passwordInputFinishSignal_tb = 1'b0;
       inputNextSignal_tb           = 1'b1;
       inputNumber_tb               = randomPassword[23:16];
     join
     #NsPerOp;

    fork
      inputNextSignal_tb = #InputSignalDelay 1'b0;
      inputNumber_tb     = randomPassword[15:8];
    join
    #NsPerOp;

    fork
      inputNextSignal_tb = #InputSignalDelay 1'b1;
      inputNumber_tb     = randomPassword[7:0];
    join
    #NsPerOp;

    #NsPerOp;

    // 检查正确密码
    fork
      passwordInputFinishSignal_tb = 1'b1;
    join
    #(1.5 * NsPerClk * `CLOCKS_PER_SEC);
    #NsPerOp

     // 清空
     fork
       resetSignal_tb = 1'b1;
     join
     #NsPerOp;

    // 回到设置模式
    fork
      modeSettingWire_tb = 1'b0;
    join
    #NsPerOp;

    $finish;
  end

endmodule

/* verilator lint_on BLKSEQ */

`default_nettype wire
