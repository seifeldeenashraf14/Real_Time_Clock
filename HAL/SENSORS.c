#include "SENSORS.h"


u16 SENSOR_TempRead(void)
{
	u16 volt =ADC_ReadVolt(LM35_CH);
	u16 temp=volt/10;
	return temp;
}
