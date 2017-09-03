#include <stdexcept>

//      LETTER MATRIX
//      *************
// 01:  PItYUisBSten *
// 02:  halfVquarter *
// 03:  LtwentyfiveF
// 04:  topastKtwone
// 05:  sevensixfour
// 06:  fivelevenine
// 07:  tenthreeight
// 08:  pmidnightDam
// 09:
// 10:
// 11:
// 12:

boolean IT_S[] = {
  false, true,  true,  false, false, true,  true,  false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean ONE[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false,  true,  true,  true, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean TWO[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false,  true,  true,  true, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean THREE[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false,  true,  true,  true,  true,  true,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean FOUR[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
   true,  true,  true,  true, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean FIVE[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false,  true,  true,  true,  true, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean SIX[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false,  true,  true,  true, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean SEVEN[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  true,  true,  true,  true,  true, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean EIGHT[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false,  true,  true,  true,  true,  true, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean NINE[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false,  true,  true,  true,  true, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean TEN[] = {
  false, false, false, false, false, false, false, false, false, true, true, true,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean ELEVEN[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  true,  true,  true,  true,  true,  true, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean NOON[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  false,  false,  false,  false,  false,  false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean MIDNIGHT[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  false,  false,  false,  false,  false,  false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean PAST[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false,  true,  true,  true,  true, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean TO[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  true,  true, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean MIN_FIVE[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false,  true,  true,  true,  true, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean MIN_TEN[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false,  true,  true,  true, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean MIN_A_QUARTER[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, true,  false, false, false, false, true,  true,  true,  true,  true,  true,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean MIN_TWENTY[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  true,  true,  true,  true,  true,  true, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean MIN_HALF[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  true,  true,  true,  true,  false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean O_CLOCK[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false,  true,  true,  true,  true,  true,  true, false,
};

boolean AM[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  false,  false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean PM[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false,  false,  false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

boolean WIFI[] = {
  false, false, false, false, false, false, false, false, false, false, false, false,
   true, false, false, false, false, false, false, false, false, false, false, false,
   true, false, false, false, false, false, false, false, false, false, false, false,
   true, false, false, false, false, false, false, false, false, false, false, false,
   true, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
  false, false, false, false, false, false, false, false, false, false, false, false,
};

void getWiFiMatrix(boolean matrix[]) {
  reset(matrix);
  combine(matrix, WIFI);
}

void getTimeMatrix(boolean matrix[], int h, int m, int s) {
  String timeString;
  
  Serial.println("");
  Serial.print(F("Time: "));   Serial.print(h);  Serial.print(F(":")); if(m < 10) Serial.print("0");  Serial.print(m);  Serial.print(F(":")); if(s <10) Serial.print("0");  Serial.print(s);

  reset(matrix);
  //we combine the matrix and logging string at the same time!    
  timeString += addPrefix(matrix, m, h);
  timeString += addMinutes(matrix, m);
  timeString += addSeparator(matrix, m);
  timeString += addHours(matrix, m, h);  
  timeString += addSuffix(matrix, m, h);
  
  Serial.println("");Serial.print(F("Words: ")); Serial.print(timeString);
  Serial.println("");Serial.println("");
}

void reset(boolean matrix[]) {
  for (int i=0; i<LEDS_COUNT; i++) {
    matrix[i] = false;
  }
}

String addPrefix(boolean matrix[], int minutes, int hours) {
  combine(matrix, IT_S);  
  return "It is ";
}

String addHours(boolean matrix[], int minutes, int hours) {
  String hourString;
  int displayedHour = hours;
  if (minutes >= 35) {
    displayedHour++;
  } 
  
  if (displayedHour == 0 || displayedHour == 24) {
    combine(matrix, MIDNIGHT);
    hourString = "midnight";
  } else if (displayedHour == 1 || displayedHour == 13) {
    combine(matrix, ONE);
    hourString = "one";
  } else if (displayedHour == 2 || displayedHour == 14) {
    combine(matrix, TWO);
    hourString = "two";
  } else if (displayedHour == 3 || displayedHour == 15) {
    combine(matrix, THREE);
    hourString = "three";
  } else if (displayedHour == 4 || displayedHour == 16) {
    combine(matrix, FOUR);
    hourString = "four";
  } else if (displayedHour == 5 || displayedHour == 17) {
    combine(matrix, FIVE);
    hourString = "five";
  } else if (displayedHour == 6 || displayedHour == 18) {
    combine(matrix, SIX);
    hourString = "six";
  } else if (displayedHour == 7 || displayedHour == 19) {
    combine(matrix, SEVEN);
    hourString = "seven";
  } else if (displayedHour == 8 || displayedHour == 20) {
    combine(matrix, EIGHT);
    hourString = "eight";
  } else if (displayedHour == 9 || displayedHour == 21) {
    combine(matrix, NINE);
    hourString = "nine";
  } else if (displayedHour == 10 || displayedHour == 22) {
    combine(matrix, TEN);
    hourString = "ten";
  } else if (displayedHour == 11 || displayedHour == 24) {
    combine(matrix, ELEVEN);
    hourString = "eleven";
  } else if (displayedHour == 12) {
    combine(matrix, NOON);
    hourString = "noon";
  }

  return hourString;
}

String addSeparator(boolean matrix[], int minutes) {
  if (minutes < 5) {
    return " ";
  } else if (minutes < 35) {
    combine(matrix, PAST);
    return " past ";
  } else {
    combine(matrix, TO);
    return " to ";
  }
}

String addMinutes(boolean matrix[], int minutes) {
  if (minutes < 5) {
    //do nothing
    return "";
  } else if (minutes < 10 || minutes >= 55) {
    combine(matrix, MIN_FIVE);
    return "five";
  } else if (minutes < 15 || minutes >= 50) {
    combine(matrix, MIN_TEN);
    return "ten";
  } else if (minutes < 20 || minutes >= 45) {
    combine(matrix, MIN_A_QUARTER);
    return "a quarter";
  } else if (minutes < 25 || minutes >= 40) {
    combine(matrix, MIN_TWENTY);
    return "twenty";
  } else if (minutes < 30 || minutes >= 35) {
    combine(matrix, MIN_TWENTY);
    combine(matrix, MIN_FIVE);
    return "twenty five";
  } else if (minutes >= 30 || minutes < 35){
    combine(matrix, MIN_HALF);
    return "half";
  }
}

String addSuffix(boolean matrix[], int minutes, int hours) {
  String suffix;
  int displayedHour = hours;
  if (minutes >= 35) {
    displayedHour++;
  } 
  
  if (minutes < 5) {
    combine(matrix, O_CLOCK);
    suffix += " o'clock";
  }
  
  if (displayedHour > 0 && displayedHour < 12) {
    combine(matrix, AM);
    suffix += " am";
  } else if (displayedHour > 12 && displayedHour < 24) {
    combine(matrix, PM);
    suffix += " pm";
  }

  return suffix;
}

void combine(boolean result[], boolean other[]) {
  for (int i=0; i<LEDS_COUNT; i++) {
    result[i] = result[i] || other[i];
  }
}
