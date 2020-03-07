#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void Signal_North(void *arg);
void Signal_South(void *arg);
void Signal_East(void *arg);
void Signal_West(void *arg);
#define GREEN_TIMER_MAX 30
#define MAX_TIMER 120
typedef enum color
{
	RED=0,
	GREEN
}ecolor;
void *Signal_Gate4(void *arg)
{
	int Value=RED;
	int timer=120;
	while(1)
	{
		if(timer ==GREEN_TIMER_MAX)
		{
			Value = GREEN;
		}
		if(timer<=0)
		{
			timer = MAX_TIMER;
			Value = RED;
		}
		printf("Gate_4 staus %s= : timer =%d ;\n ",Value?"GREEN":"RED",timer);			
		timer--;
		usleep(1000000);
	}

}
void *Signal_Gate3(void *arg)
{
	int Value=RED;
	int timer=90;
	while(1)
	{
		if(timer ==GREEN_TIMER_MAX)
		{
			Value = GREEN;
		}
		if(timer <= 0)
		{
			timer = 120;
			Value= RED;
			
		}
		printf("Gate_3 staus %s= : timer =%d ;\n ",Value?"GREEN":"RED",timer);
		timer--;
		usleep(1000000);

	}
}
void *Signal_Gate2(void *arg)
{
	int Value=RED;
	int timer=60;
	while(1)
	{
		if(timer == GREEN_TIMER_MAX)
		{
			Value=GREEN;
		}
		if(timer <= 0)
		{
			Value=RED;
			timer = 120;

		}
		printf("Gate_2 staus %s= : timer =%d ;\n ",Value?"GREEN":"RED",timer);
		timer--;
		usleep(1000000);
	}
}

void *Signal_Gate1(void *arg)
{
	int Value=GREEN;
	int timer=30;
	while(1)
	{
		
		if(timer == GREEN_TIMER_MAX)
		{
			Value=GREEN;
		}
		if(timer <= 0)
		{
			Value=RED;
			timer=120;
		}
		printf("Gate_1 staus %s= : timer =%d ;\n ",Value?"GREEN":"RED",timer);
		timer--;
		usleep(1000000);
		
	}
}
int main()
{
	int error;
	pthread_t South,North,West,East;
	/*Thread creation*/
	error=pthread_create(&South,NULL,Signal_Gate1,NULL);
	error=pthread_create(&North,NULL,Signal_Gate2,NULL);
	error= pthread_create(&West,NULL,Signal_Gate3,NULL);
	error=pthread_create(&East,NULL,Signal_Gate4,NULL);
	/*Thread join*/
	pthread_join(South,NULL);
	pthread_join(North,NULL);
	pthread_join(West,NULL);
	pthread_join(East,NULL);

	
}
