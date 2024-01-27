

#ifndef UTILS_H_
#define UTILS_H_
#define READ_Bit(Reg,Bit) ((Reg>>Bit)&1)
#define SET_Bit(Reg,Bit) (Reg=Reg|(1<<Bit))
#define CLR_Bit(Reg,Bit) (Reg=Reg&(~(1<<Bit)))
#define TOG_Bit(Reg,Bit) (Reg=Reg^(1<<Bit))
//#define F_CPU 8000000
#include <util/delay.h>
#endif /* UTILS_H_ */
