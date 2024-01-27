


#ifndef SENSORS_H_
#define SENSORS_H_

#include "StdTypes.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

/* return c*10*/
u16 SENSOR_TempRead(void);
u16 SENSOR_PressureRead(void);


#define LM35_CH CH_0

#endif /* SENSORS_H_ */