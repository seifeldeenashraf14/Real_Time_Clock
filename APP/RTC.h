#ifndef RTC_H_
#define RTC_H_


typedef enum {
start,
Waiting,
Hours_done,
Minutes_done,
Secondes_done,
NOK
}RTC_type;



void RTC_voidinit(void);
void RTC_void(void);
RTC_type RTC_enuFirstSettings(u8 RTC_x,u8*num);
RTC_type RTC_enuConvert(RTC_type is_setting,u8* num);
void RTC_voidFixTime(void);
#endif /* RTC*/




