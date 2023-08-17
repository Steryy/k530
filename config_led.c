#ifdef RGB_MATRIX_ENABLE

#    include "rgb_matrix.h"
#    include "config_led.h"
#define YMULT 16
#define XMULT 17
led_config_t g_led_config = { {
  {   0,      1,   2,       3,      4,      5,   6,      7,      8,      9,     10,     11,     12,     13, },
  {  14,     15,  16,      17,     18,     19,  20,     21,     22,     23,     24,     25,     26,     27, },
  {  28,     29,  30,      31,     32,     33,  34,     35,     36,     37,     38,     39, NO_LED,     40, },
  {  41, NO_LED,  42,      43,     44,     45,  46,     47,     48,     49,     50,     51, NO_LED,     52, },
  {  53,     54,  55,  61,62 ,NO_LED,  56, NO_LED, NO_LED,     57,     58, NO_LED,     59,     60, },
}, {
    { 1 *XMULT, YMULT*0}, { 2 *XMULT, YMULT*0}, { 3 *XMULT, YMULT*0}, { 4 *XMULT, YMULT*0}, { 5 *XMULT, YMULT*0}, { 6 *XMULT, YMULT*0},  { 7 *XMULT, YMULT*0}, { 8 *XMULT, YMULT*0}, { 9 *XMULT, YMULT*0}, { 10*XMULT, YMULT*0}, { 11*XMULT, YMULT*0}, { 12*XMULT, YMULT*0}, { 13*XMULT, YMULT*0}, { 14*XMULT, YMULT*0},
    { 1 *XMULT, YMULT*1}, { 2 *XMULT, YMULT*1}, { 3 *XMULT, YMULT*1}, { 4 *XMULT, YMULT*1}, { 5 *XMULT, YMULT*1}, { 6 *XMULT, YMULT*1},  { 7 *XMULT, YMULT*1}, { 8 *XMULT, YMULT*1}, { 9 *XMULT, YMULT*1}, { 10*XMULT, YMULT*1}, { 11*XMULT, YMULT*1}, { 12*XMULT, YMULT*1}, { 13*XMULT, YMULT*1}, { 14*XMULT, YMULT*1},
    { 1 *XMULT, YMULT*2}, { 2 *XMULT, YMULT*2}, { 3 *XMULT, YMULT*2}, { 4 *XMULT, YMULT*2}, { 5 *XMULT, YMULT*2}, { 6 *XMULT, YMULT*2},  { 7 *XMULT, YMULT*2}, { 8 *XMULT, YMULT*2}, { 9 *XMULT, YMULT*2}, { 10*XMULT, YMULT*2}, { 11*XMULT, YMULT*2}, { 12*XMULT, YMULT*2},               { 14*XMULT, YMULT*2},
    { 1 *XMULT, YMULT*3},               { 3 *XMULT, YMULT*3}, { 4 *XMULT, YMULT*3}, { 5 *XMULT, YMULT*3}, { 6 *XMULT, YMULT*3},  { 7 *XMULT, YMULT*3}, { 8 *XMULT, YMULT*3}, { 9 *XMULT, YMULT*3}, { 10*XMULT, YMULT*3}, { 11*XMULT, YMULT*3}, { 12*XMULT, YMULT*3},               { 14*XMULT, YMULT*3},
    { 1 *XMULT, YMULT*4}, { 2 *XMULT, YMULT*4}, { 3 *XMULT, YMULT*4},                                            { 7 *XMULT, YMULT*4},                              { 10*XMULT, YMULT*4}, { 11*XMULT, YMULT*4},               { 13*XMULT, YMULT*4}, { 14*XMULT, YMULT*4},
}, {
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
   4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
   4, 4, 4,          4,       4, 4,    4, 4,
} };

#endif
