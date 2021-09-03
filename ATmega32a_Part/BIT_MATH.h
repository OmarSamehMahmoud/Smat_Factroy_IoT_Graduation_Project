#ifndef BIT_MATH
#define BIT_MATH

#define SET_BIT(Var,Bitnum) Var|=(1<<Bitnum)

#define CLR_BIT(Var,Bitnum) Var=Var&(~(1<<Bitnum))

#define GET_BIT(Var,Bitnum) (((Var)&(1<<Bitnum))>>Bitnum)

#define TOOGLE_BIT(Var,Bitnum)  Var^=(1<<Bitnum)

#endif
