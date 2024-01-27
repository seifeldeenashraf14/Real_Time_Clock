#include "Servo.h"



void Servo_Init(void)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	OCR1A=1499;
	ICR1=19999;
}
void Servo_SetPosition(u8 angle)
{
	OCR1A=((angle*(u32)1000)/180)+999;
}
