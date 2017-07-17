`include "parameters.vh"

module cache
(
    input                                                       reset,
    input                                                       clk,

    //To CPU Core
    output  [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0]     cache_packet_to_core,
    input   [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0]     cache_packet_from_core,

    //To Mem
    output  [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0]     cache_packet_to_mem,
    input   [(`CACHE_PACKET_WIDTH_IN_BITS)         - 1 : 0]     cache_packet_from_mem
);  

    wire tag_access_en,tag_write_en,valid_access_en,history_access_en,valid_write_en,history_write_en,valid_write,history_write,data_access_en,data_write_en;
    wire [(`CACHE_INDEX_LEN_IN_BITS)-1:0]tag_access_set_addr,data_access_set_addr;
    wire [(`CACHE_TAG_LEN_IN_BITS)-1:0]tag_to_compare,tag_write;
    wire [(`CACHE_SET_ASSOCIATIVITY)-1:0]tag_ways_select_out,ways_select,history_ways_select,valid_vec,history_vec;
    wire [(`CACHE_BLOCK_SIZE_IN_BITS)-1:0]data_write,data_read;



cache_ctrl cache_ctrl
(
    .reset_in                   (reset),
    .clk_in                     (clk),

    .cache_packet_from_core_in  (cache_packet_from_core),
    .cache_packet_to_core_out   (cache_packet_to_core),

    .cache_packet_from_mem_in   (cache_packet_from_mem),
    .cache_packet_to_mem_out    (cache_packet_to_mem),

    .tag_access_en_out          (tag_access_en),
    .tag_write_en_out           (tag_write_en),
    .tag_access_set_addr_out    (tag_access_set_addr),
    .tag_to_compare_out         (tag_to_compare),
    .tag_write_out              (tag_write),

    .ways_select_out            (ways_select),
    .ways_select_in             (tag_ways_select_out),

    .valid_access_en_out        (valid_access_en),
    .history_access_en_out      (history_access_en),
    .valid_write_en_out         (valid_write_en),
    .history_write_en_out       (history_write_en),  
    .valid_vec_in               (valid_vec),
    .history_vec_in             (history_vec),
    .valid_write_out            (valid_write),
    .history_write_out          (history_write),
    .history_ways_select_out    (history_ways_select),

    .data_access_en_out         (data_access_en),
    .data_write_en_out          (data_write_en),
    .data_access_set_addr_out   (data_access_set_addr),
    .data_write_out             (data_write),
    .data_read_in               (data_read)
);

cache_array
#(
    .SINGLE_ELEMENT_SIZE_IN_BITS    (`CACHE_TAG_LEN_IN_BITS),
    .NUMBER_WAYS                    (`CACHE_SET_ASSOCIATIVITY),
    .NUMBER_SETS                    (`CACHE_NUM_SETS),
    .SET_PTR_WIDTH_IN_BITS          (`CACHE_INDEX_LEN_IN_BITS)
)
tag_storage
(
    .reset_in                       (reset),
    .clk_in                         (clk),

    .access_en_in                   (tag_access_en),
    .write_en_in                    (tag_write_en),
    .access_set_addr_in             (tag_access_set_addr),
    .ways_select_in                 (ways_select),

    .compare_in                     (tag_to_compare),
    .ways_select_out                (tag_ways_select_out),

    .write_element_in               (tag_write),
    .read_element_out               (),
    .read_full_elements_out         ()
);

cache_array
#(
    .SINGLE_ELEMENT_SIZE_IN_BITS    (`CACHE_BLOCK_SIZE_IN_BITS),
    .NUMBER_WAYS                    (`CACHE_SET_ASSOCIATIVITY),
    .NUMBER_SETS                    (`CACHE_NUM_SETS),
    .SET_PTR_WIDTH_IN_BITS          (`CACHE_INDEX_LEN_IN_BITS)
)
data_storage
(
    .reset_in                       (reset),
    .clk_in                         (clk),

    .access_en_in                   (data_access_en),
    .write_en_in                    (data_write_en),
    .access_set_addr_in             (data_access_set_addr),
    .ways_select_in                 (ways_select),

    .compare_in                     (),
    .ways_select_out                (),

    .write_element_in               (data_write),
    .read_element_out               (data_read),
    .read_full_elements_out         ()
);

cache_array
#(
    .SINGLE_ELEMENT_SIZE_IN_BITS    (1),
    .NUMBER_WAYS                    (`CACHE_SET_ASSOCIATIVITY),
    .NUMBER_SETS                    (`CACHE_NUM_SETS),
    .SET_PTR_WIDTH_IN_BITS          (`CACHE_INDEX_LEN_IN_BITS)
)
history_array
(
    .reset_in                       (reset),
    .clk_in                         (clk),

    .access_en_in                   (history_access_en),
    .write_en_in                    (history_write_en),
    .access_set_addr_in             (tag_access_set_addr),
    .ways_select_in                 (history_ways_select),

    .compare_in                     (),
    .ways_select_out                (),

    .write_element_in               (history_write),
    .read_element_out               (),
    .read_full_elements_out         (history_vec)
);

cache_array
#(
    .SINGLE_ELEMENT_SIZE_IN_BITS    (1),
    .NUMBER_WAYS                    (`CACHE_SET_ASSOCIATIVITY),
    .NUMBER_SETS                    (`CACHE_NUM_SETS),
    .SET_PTR_WIDTH_IN_BITS          (`CACHE_INDEX_LEN_IN_BITS)
)
valid_array
(
    .reset_in                       (reset),
    .clk_in                         (clk),

    .access_en_in                   (valid_access_en),
    .write_en_in                    (valid_write_en),
    .access_set_addr_in             (tag_access_set_addr),
    .ways_select_in                 (ways_select),

    .compare_in                     (),
    .ways_select_out                (),

    .write_element_in               (valid_write),
    .read_element_out               (),
    .read_full_elements_out         (valid_vec)
);

endmodule