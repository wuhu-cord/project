#ifndef  TIMWE_H
#define TIMWE_H
#include<SDL3/SDL.h>
typedef struct
{
	Uint64 start_time;   // 开始时间（SDL时间戳）
	Uint64 paused_time;  // 暂停累计时间
	int is_running;      // 计时器是否运行（1=运行，0=暂停）
}Timer;
void Timer_Init(Timer* timer);
void Timer_Start(Timer* timer);
void Timer_Pause(Timer* timer);
double Timer_GetElapsedSeconds(Timer* timer);
#endif
