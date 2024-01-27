/**************************************/
/* Description : SevenSegment c File  */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 10:19:33  05 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "SEVENSEGMENT.h"
#include "SEVENSEGMENT_cfg.h"
#include "SEVENSEGMENT_priv.h"




tenuErrrorStatus SEV_enuDisplay(u8 u8SevIndexCpy, u8 u8NumCpy)
{

	tenuErrrorStatus enuReturnLoc =EOK;
	u8 au8cathode[10] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	if (u8NumCpy<10)
	{
		if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_CATHODE)
		{
			SEV_HexToBin(u8SevIndexCpy,au8cathode[u8NumCpy]);

		}
		else if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_ANODE)
		{
			SEV_HexToBin(u8SevIndexCpy,~au8cathode[u8NumCpy]);

		}
		else
		{
			enuReturnLoc=ENOK;

		}
	}
	else
	{
		enuReturnLoc=PARAMRETER_OUT_RANGE;
	}
	return enuReturnLoc;


}


 void SEV_HexToBin(u8 u8SevIndexCpy,u8 u8HexCpy ) // 0b0111111  num 0
{
	static DIO_PinVoltage_type au8BinValuesLoc[7];
	u8 u8CounterLoc;
	for (u8CounterLoc=0; u8CounterLoc<7;u8CounterLoc++)
	{
		au8BinValuesLoc[u8CounterLoc]=READ_Bit(u8HexCpy,u8CounterLoc);
		//DIO_voidWritePin(PINC1,HIGH);
	}
	DIO_enuWriteGroup(SEV_ConfigSet[u8SevIndexCpy].au8SevCon,au8BinValuesLoc,7);

}

tenuErrrorStatus SEV_enuEnable(u8 u8SevIndexCpy)
{

	tenuErrrorStatus enuReturnLoc =EOK;
	if (u8SevIndexCpy < SEV_MAX_NUM)
	{
		if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_CATHODE)
		{
			DIO_voidWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,LOW);
		}
		else if  (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_ANODE)
		{
			DIO_voidWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,HIGH);
		}
		else
		{
			enuReturnLoc=ENOK;

		}
	}
	else
	{
		enuReturnLoc =PARAMRETER_OUT_RANGE;
	}

	return enuReturnLoc;
}
tenuErrrorStatus SEV_enuDisable(u8 u8SevIndexCpy)
{
	tenuErrrorStatus enuReturnLoc =EOK;
		if (u8SevIndexCpy < SEV_MAX_NUM)
		{
			if (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_CATHODE)
			{
				DIO_voidWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,HIGH);

			}
			else if  (SEV_ConfigSet[u8SevIndexCpy].u8ConMode==COMMON_ANODE)
			{
				DIO_voidWritePin(SEV_ConfigSet[u8SevIndexCpy].u8common ,LOW);

			}
			else
			{

				enuReturnLoc=ENOK;

			}
		}
		else
		{
			enuReturnLoc =PARAMRETER_OUT_RANGE;
		}

		return enuReturnLoc;
}

void Seven_voidDisplay_Mlx(u8 u8NumCpy,u8 index){

	u8 d0 =0;
	d0=u8NumCpy%10;
	u8 d1 =0;
	d1=u8NumCpy/10;
	SEV_enuEnable(index);
	SEV_enuDisplay(index,d0);
	_delay_us(4000);
	SEV_enuDisable(index+1);
	SEV_enuEnable(index+1);
	SEV_enuDisplay(index+1,d1);
	_delay_us(4000);
	SEV_enuDisable(index);

}
/*DDR_segment=0xff;
	DDR_segment_2=0xff;
	s8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	s8 d0=n%10;
	s8 d1=n/10;
	SET_Bit(PORTD,0);
	PORTC=arr[d0];
	CLR_Bit(PORTD,1);
	_delay_ms(10);
	SET_Bit(PORTD,1);
	PORTC=arr[d1];
	CLR_Bit(PORTD,0);
	_delay_ms(10);*/
