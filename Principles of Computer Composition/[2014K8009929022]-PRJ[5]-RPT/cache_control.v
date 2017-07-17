`include "parameters.vh"

module cache_ctrl
(
    input reset_in,
    input clk_in,
    input  [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0] cache_packet_from_core_in,
    output reg [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0] cache_packet_to_core_out,
    input  [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0] cache_packet_from_mem_in,
    output reg [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0] cache_packet_to_mem_out,
    output tag_access_en_out,
    output tag_write_en_out,
    output reg [(`CACHE_INDEX_LEN_IN_BITS)-1:0]tag_access_set_addr_out,
    output [(`CACHE_TAG_LEN_IN_BITS)-1:0]tag_to_compare_out,
    output [(`CACHE_TAG_LEN_IN_BITS)-1:0]tag_write_out,
    output reg [(`CACHE_SET_ASSOCIATIVITY)-1:0]ways_select_out,
    input [(`CACHE_SET_ASSOCIATIVITY)-1:0]ways_select_in,
    output valid_access_en_out,
    output history_access_en_out,
    output valid_write_en_out,
    output history_write_en_out,
    input [(`CACHE_SET_ASSOCIATIVITY)-1:0]valid_vec_in,
    input [(`CACHE_SET_ASSOCIATIVITY)-1:0]history_vec_in,
    output valid_write_out,
    output history_write_out,
    output reg [(`CACHE_SET_ASSOCIATIVITY)-1:0]history_ways_select_out,
    output data_access_en_out,
    output data_write_en_out,
    output [(`CACHE_INDEX_LEN_IN_BITS)-1:0]data_access_set_addr_out,
    output reg [(`CACHE_BLOCK_SIZE_IN_BITS)-1:0]data_write_out,
    input [(`CACHE_BLOCK_SIZE_IN_BITS)-1:0]data_read_in
);

    reg [2:0]State,NState;
    reg [(`CACHE_SET_ASSOCIATIVITY)-1:0]ways_select;
    reg [(`CACHE_PACKET_WIDTH_IN_BITS)-1:0]cache_packet_from_core;
    reg hit;
    reg [1:0]solution;

    wire write;
    wire packetwrite;
    wire [(`CACHE_SET_ASSOCIATIVITY)-1:0]new_ways;
    wire [1:0]newsolution;
    wire state[4:0];
    
    queue queue(.valid_vec_in(valid_vec_in),.history_vec_in(history_vec_in),.ways_select_in(ways_select_in),.new_ways(new_ways),.solution(newsolution));

    assign state[0]=(State==3'd0)? 1:0;
    assign state[1]=(State==3'd1)? 1:0;
    assign state[2]=(State==3'd2)? 1:0;
    assign state[3]=(State==3'd3)? 1:0;
    assign state[4]=(State==3'd4)? 1:0;
    
    assign packetwrite=state[0]&&cache_packet_from_core_in[`CACHE_PACKET_VALID_POS];
    assign write=state[1];

    assign valid_write_out=1;
    assign history_write_out=state[2]&&hit;
    assign tag_write_out=cache_packet_from_core[`CACHE_TAG_POS_HI:`CACHE_TAG_POS_LO];
    assign tag_write_en_out=state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS];
    assign tag_to_compare_out=cache_packet_from_core[`CACHE_TAG_POS_HI:`CACHE_TAG_POS_LO];
    assign valid_write_en_out=state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS];
    assign tag_access_en_out=state[0]||(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS]);
    assign valid_access_en_out=state[0]||(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS]);
    assign data_access_en_out=(state[2]&&hit)||(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS]);
    assign history_write_en_out=(state[2]&&hit)||(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS]);
    assign data_access_set_addr_out=(state[2]||state[4])&&cache_packet_from_core[`CACHE_INDEX_POS_HI:`CACHE_INDEX_POS_LO];
    assign history_access_en_out=state[0]||(state[2]&&hit)||(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS]);
    assign data_write_en_out=(state[2]&&hit&&cache_packet_from_core[`CACHE_PACKET_IS_WRITE_POS])||(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS]);

    always@(*)
    begin
      case(State)
        3'd0:
        begin
          data_write_out=0;
          tag_access_set_addr_out=cache_packet_from_core_in[`CACHE_INDEX_POS_HI:`CACHE_INDEX_POS_LO];
          ways_select_out=(1<<(`CACHE_SET_ASSOCIATIVITY))-1;
        end
        3'd2:
        begin
          data_write_out=cache_packet_from_core[`CACHE_PACKET_DATA_POS_HI:`CACHE_PACKET_DATA_POS_LO];
          tag_access_set_addr_out=cache_packet_from_core[`CACHE_INDEX_POS_HI:`CACHE_INDEX_POS_LO];
          ways_select_out=ways_select;
        end
        3'd4:
        begin
          data_write_out=cache_packet_from_mem_in[`CACHE_PACKET_DATA_POS_HI:`CACHE_PACKET_DATA_POS_LO];
          tag_access_set_addr_out=cache_packet_from_core[`CACHE_INDEX_POS_HI:`CACHE_INDEX_POS_LO];
          ways_select_out=ways_select;
        end
        default:
        begin
          data_write_out=0;
          tag_access_set_addr_out=cache_packet_from_core[`CACHE_INDEX_POS_HI:`CACHE_INDEX_POS_LO];
          ways_select_out=0;
        end
      endcase

      if(state[4]&&solution==2'b11)
        history_ways_select_out=(1<<(`CACHE_SET_ASSOCIATIVITY))-1;
      else
        history_ways_select_out=ways_select_out;

      if(state[2])
        begin
          case({cache_packet_from_core[`CACHE_PACKET_IS_WRITE_POS],hit})
          2'b01:cache_packet_to_mem_out=0;
          default:cache_packet_to_mem_out=cache_packet_from_core;
          endcase
        end
      else
          cache_packet_to_mem_out=0;

      if(state[2])
        begin
          case(cache_packet_from_core[`CACHE_PACKET_IS_WRITE_POS])
          1'b0:cache_packet_to_core_out=0;
          1'b1:cache_packet_to_core_out=cache_packet_from_core;
          default:cache_packet_to_core_out=0;
          endcase
        end
      else if(state[3])
        cache_packet_to_core_out={cache_packet_from_core[(`CACHE_PACKET_WIDTH_IN_BITS)-1:(`CACHE_PACKET_DATA_POS_HI)+1],data_read_in,cache_packet_from_core[`CACHE_PACKET_ADDR_POS_HI:`CACHE_PACKET_ADDR_POS_LO]};
      else if(state[4]&&cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS])
        cache_packet_to_core_out=cache_packet_from_mem_in;
      else
        cache_packet_to_core_out=0;
        
    end

    always@(*)
    begin
      case(State)
      3'd0:
      begin
        if(cache_packet_from_core_in[`CACHE_PACKET_VALID_POS])
          NState=3'd1;
        else
          NState=3'd0;
      end
      3'd1:NState=3'd2;
      3'd2:
      begin
        case({cache_packet_from_core[65],hit})
        2'b01:NState=3'd3;
        2'b00:NState=3'd4;
        default:NState=3'd0;
        endcase
      end
      3'd4:
      begin
        if (cache_packet_from_mem_in[`CACHE_PACKET_VALID_POS])
          NState=3'd0;
        else
          NState=3'd4;
      end
      default:NState=3'd0;
      endcase
    end

    always@(posedge reset_in or posedge clk_in)
    begin
      if(reset_in)
        begin
          State<=3'd0;
          cache_packet_from_core<=0;
          ways_select<=0;
          solution<=0;
          hit<=0;
        end
      else 
        begin
          State<=NState;
          if(packetwrite)
            cache_packet_from_core<=cache_packet_from_core_in;   
          if(write)
            begin
              ways_select<=new_ways;
              solution<=newsolution;
              hit<=|(valid_vec_in&ways_select_in);
            end
        end
    end

endmodule