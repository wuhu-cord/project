#include"timer.h"
#include<SDL3/SDL.h>
void Timer_Init(Timer* timer)
{
	timer->start_time = 0;
	timer->paused_time = 0;
	timer->is_running = 0;
}
void Timer_Start(Timer* timer)
{
	if (!timer->is_running)
	{
		timer->start_time = SDL_GetPerformanceCounter() - timer->paused_time;
		timer->is_running = 1;
	}
}
static void Timer_pause(Timer* timer)
{
	if (timer->is_running)
	{
		timer->paused_time = SDL_GetPerformanceCounter() - timer->start_time;
		timer->is_running = 0;
	}
}
double Timer_GetElapsedSeconds(Timer* timer)
{
	Uint64 elapsed_time;
	if (timer->is_running)
	{
		elapsed_time = SDL_GetPerformanceCounter() - timer->start_time;
	}
	else
	{
		elapsed_time = timer->paused_time;
	}
	return (double)elapsed_time / SDL_GetPerformanceFrequency();
}
