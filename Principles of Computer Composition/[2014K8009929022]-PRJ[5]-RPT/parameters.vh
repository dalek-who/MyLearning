//General
//You Can't Modify this segment of codes
`define BYTE_LEN_IN_BITS                         8
`define CPU_WORD_LEN_IN_BITS                     32
`define CPU_WORD_LEN_IN_BYTES                    (`CPU_WORD_LEN_IN_BITS) / (`BYTE_LEN_IN_BITS)

//Cache Parameters
//You May change the first 2 lines of codes only
`define CACHE_SIZE_IN_BYTES                      4 * 1024
`define CACHE_SET_ASSOCIATIVITY                  4        

`define CACHE_BLOCK_SIZE_IN_BYTES                4
`define CACHE_NUM_SETS                           (`CACHE_SIZE_IN_BYTES) / (`CACHE_SET_ASSOCIATIVITY) / (`CACHE_BLOCK_SIZE_IN_BYTES)
`define CACHE_BLOCK_OFFSET_LEN_IN_BITS           $clog2(`CACHE_BLOCK_SIZE_IN_BYTES)
`define CACHE_BLOCK_SIZE_IN_BITS                 (`CACHE_BLOCK_SIZE_IN_BYTES) * 8
`define CACHE_BLOCK_OFFSET_POS_HI                (`CACHE_BLOCK_OFFSET_LEN_IN_BITS) - 1
`define CACHE_BLOCK_OFFSET_POS_LO                0
`define CACHE_INDEX_LEN_IN_BITS                  $clog2(`CACHE_NUM_SETS)
`define CACHE_INDEX_POS_HI                       (`CACHE_BLOCK_OFFSET_LEN_IN_BITS) + (`CACHE_INDEX_LEN_IN_BITS) - 1
`define CACHE_INDEX_POS_LO                       (`CACHE_BLOCK_OFFSET_LEN_IN_BITS)
`define CACHE_TAG_LEN_IN_BITS                    (`CPU_WORD_LEN_IN_BITS) - (`CACHE_BLOCK_OFFSET_LEN_IN_BITS) - (`CACHE_INDEX_LEN_IN_BITS)
`define CACHE_TAG_POS_HI                         (`CACHE_BLOCK_OFFSET_LEN_IN_BITS) + (`CACHE_INDEX_LEN_IN_BITS) + (`CACHE_TAG_LEN_IN_BITS) - 1
`define CACHE_TAG_POS_LO                         (`CACHE_BLOCK_OFFSET_LEN_IN_BITS) + (`CACHE_INDEX_LEN_IN_BITS)

//cache <==> core packet format
//You Can't Modify this segment of codes
`define CACHE_PACKET_WIDTH_IN_BITS               (`CPU_WORD_LEN_IN_BITS) + (`CACHE_BLOCK_SIZE_IN_BITS) + 2
`define CACHE_PACKET_ADDR_POS_LO                 0
`define CACHE_PACKET_ADDR_POS_HI                 (`CACHE_PACKET_ADDR_POS_LO) + (`CPU_WORD_LEN_IN_BITS) - 1
`define CACHE_PACKET_DATA_POS_LO                 (`CACHE_PACKET_ADDR_POS_HI) + 1
`define CACHE_PACKET_DATA_POS_HI                 (`CACHE_PACKET_DATA_POS_LO) + (`CACHE_BLOCK_SIZE_IN_BITS) - 1
`define CACHE_PACKET_VALID_POS                   (`CACHE_PACKET_DATA_POS_HI) + 1
`define CACHE_PACKET_IS_WRITE_POS                (`CACHE_PACKET_VALID_POS) + 1
