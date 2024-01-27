#include "TIMER_interface.h"
#include "LCD_interface.h"
#include "KeyPad_interface.h"
#include "SEVENSEGMENT.h"
#include "RTC.h"

u8 RTC_Hours,RTC_Minutes,RTC_Seconds;

void RTC_Inc(void)
{
	if(RTC_Seconds<59)
	{
		RTC_Seconds++;
	}
	else
	{
		RTC_Seconds=0;
		if(RTC_Minutes<59)
		{
			RTC_Minutes++;
		}
		else
		{
			RTC_Minutes=0;
			if(RTC_Hours<23)
			{
				RTC_Hours++;
			}
			else
			{
				RTC_Hours=0;
			}
		}

	}
}
void RTC_voidinit(void)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_256);
	Timer1_OVF_InterruptEnable();
	Timer1_OVF_SetCallBack(RTC_Inc);
	Timer1_SetICRvalue(31250);
	GLOBAL_ENABLE();
}

void RTC_void(void)
{
	static u8 RTC_x=NO_KEY,RTC_Time=0;
	RTC_type is_setting,op;
	RTC_x=KEYPAD_GetKey();
	is_setting=RTC_enuFirstSettings(RTC_x,&RTC_Time);
	op=RTC_enuConvert(is_setting,&RTC_Time);
	RTC_voidDisplay(op);

}



RTC_type RTC_enuFirstSettings(u8 RTC_x,u8*num)
{
	static u8 Counter=0,i=0;
	RTC_type is_setting=NOK;

	if(RTC_x==NO_KEY&&Counter==0)
	{
                     LCD_Clear();
			    	LCD_Setcursor(1,1);
			    	LCD_WriteString("Press 1 ");
			    	LCD_Setcursor(2,1);
			    	LCD_WriteString(" To Set Clock ");
			    	Counter++;
			    	is_setting=Waiting;
	}
	else if (RTC_x=='1'&&Counter ==1)
	{
		  LCD_Clear();
		  LCD_Setcursor(1,1);
		  LCD_WriteString("Hours:");
           Counter++;
	    	is_setting=Waiting;
	    	i=7;
	}
	else if(RTC_x!='1' && RTC_x!=NO_KEY&&Counter==1 )
	{
		LCD_Clear();
    	LCD_Setcursor(1,1);
		LCD_WriteString("Wrong Number");
		_delay_ms(1000);
		Counter=0;
		  is_setting=NOK;
	}
	else if ( (RTC_x!=NO_KEY) &&(Counter==2||Counter==3 ))
	{
		LCD_Setcursor(1,i);
		LCD_WriteChar(RTC_x);
		*num=((*num)*10)+(RTC_x-'0');
		if(Counter==3)
		{
			is_setting=Hours_done;
			_delay_ms(1000);
			  LCD_Clear();
				 LCD_Setcursor(1,1);
				 LCD_WriteString("minutes:");
				 i=9;
		}
		else
		{
			i++;
		}

		Counter++;
	}
	else if ( (RTC_x!=NO_KEY) &&(Counter==4||Counter==5))
		{
			LCD_Setcursor(1,i);
			LCD_WriteChar(RTC_x);
			*num=((*num)*10)+(RTC_x-'0');
			if(Counter==5)
			{
				is_setting=Minutes_done;
				_delay_ms(1000);
				  LCD_Clear();
					 LCD_Setcursor(1,1);
					 LCD_WriteString("Seconds:");
					 i=9;
			}
			else
			{
				i++;
			}

			Counter++;
		}
	else if ( (RTC_x!=NO_KEY) &&(Counter==6||Counter==7))
		{
			LCD_Setcursor(1,i);
			LCD_WriteChar(RTC_x);
			*num=((*num)*10)+(RTC_x-'0');
			if(Counter==7)
			{
				is_setting=Secondes_done;
				_delay_ms(1000);
			    LCD_Clear();
						    	LCD_Setcursor(1,1);
						    	LCD_WriteString("Press 1 ");
						    	LCD_Setcursor(2,1);
						    	LCD_WriteString(" To Set Clock ");
						    Counter=0;

			}
			else
			{
				i++;
			}

			Counter++;
		}
  return is_setting;
}

RTC_type RTC_enuConvert(RTC_type is_setting,u8* num)
{
	   RTC_type op=NOK;
     if(is_setting==Hours_done)
     {
    	 RTC_Hours=*num;
    	 *num=0;
     }
     else if(is_setting==Minutes_done)
     {
    	 RTC_Minutes=*num;
    	*num=0;
     }
     else if(is_setting==Secondes_done)
     {
    	 RTC_Seconds=*num-1;
    	 *num=0;
       op=start;
     }

     return op;
}


void RTC_voidDisplay(RTC_type op)
{

	switch(op)
	{
	case start :
		RTC_voidFixTime();
     break;

	}

}


void RTC_voidFixTime(void)
{   u8 RTC_x=NO_KEY;
static u8 Timer_flag=0;
	while(RTC_x!='1')
	{
	RTC_x=KEYPAD_GetKey();
		if(Timer_flag==0)
		{
			RTC_voidinit();
			Timer_flag=1;
		}
		Seven_voidDisplay_Mlx(RTC_Seconds,4);
		Seven_voidDisplay_Mlx(RTC_Minutes,2);
		Seven_voidDisplay_Mlx(RTC_Hours,0);

	}

}
