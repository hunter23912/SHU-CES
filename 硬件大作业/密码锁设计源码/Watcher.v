// ±ßÑØ¼ì²éÆ÷
module Watcher (
    input  wire clk,
    input  wire rst_n,
    input  wire signal,
    output wire pos,
    output wire neg
);

  reg [2:0] state;

  always @(posedge clk, negedge rst_n) begin
    if (!rst_n) begin
      state[0] <= 1'b0;
      state[1] <= 1'b0;
      state[2] <= 1'b0;
    end else begin
      state[0] <= signal;
      state[1] <= state[0];
      state[2] <= state[1];
    end
  end

  assign pos = state[1] & !state[2];
  assign neg = !state[1] & state[2];
endmodule
