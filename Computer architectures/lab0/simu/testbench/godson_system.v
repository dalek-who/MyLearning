`timescale 1ns/1ps

`define XILINX

`define APP_FLASH   "../flash.vlog"

`define UART_CLK    archlab_sopc_top.uart0.regs.enable

module godson_system;
// Signal Declarations                                                        //
// ========================================================================== //
// Clocks
reg clk,resetn;
initial begin
    clk = 1'b0;
    resetn = 1'b0;
  #1000;
    resetn = 1'b1;
end
always #15.15 clk = ~clk;


wire [15:0] LED;
wire [7 :0] NUM_CSn;
wire [7 :0] NUM_A_G;

wire SPI_CLK,   SPI_CS, SPI_MISO,  SPI_MOSI;

archlab_sopc_top archlab_sopc_top
    (
    .resetn  (resetn  ), 
    .clk     (clk     ),

    .LED     (LED     ),
    .NUM_CSn (NUM_CSn ),
    .NUM_A_G (NUM_A_G ),

    .SPI_CLK (SPI_CLK ),
    .SPI_CS  (SPI_CS  ),
    .SPI_MISO(SPI_MISO),
    .SPI_MOSI(SPI_MOSI)
    );



MX25L6405D #
    (
    .Init_File(`APP_FLASH)
    )
    spi_flash  
    (
    .SCLK (SPI_CLK ), 
    .CS   (SPI_CS  ), 
    .SI   (SPI_MOSI), 
    .SO   (SPI_MISO), 
    .WP   (1'b1    ), 
    .HOLD (1'b1    )
    );
endmodule
