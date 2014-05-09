

#include "stdio.h"
#include "pthread.h"

pthread_mutex_t mutex;
pthread_cond_t condition;

unsigned int i = 0;

void *threadFunc1(void *arg){

	pthread_mutex_lock(&mutex);	
	pthread_cond_wait(&condition,&mutex);
	pthread_mutex_unlock(&mutex);

	printf("aaaaaaa  %d\n",i);
	pthread_exit((void *)0);

}


void *threadFunc2(void *arg){

	pthread_mutex_lock(&mutex);	
	pthread_cond_wait(&condition,&mutex); //??? 这里人存在问题
	pthread_mutex_unlock(&mutex);

	printf("vbbbbbbbbbb %d\n",i);
	pthread_exit((void *)0);

}


int main(int argc, char const *argv[])
{
	
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&condition,NULL);

	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,threadFunc1,(void *)0);
	pthread_create(&thread2,NULL,threadFunc2,(void *)0);

	while(1){

		pthread_mutex_lock(&mutex);
		i++;
		pthread_mutex_unlock(&mutex);

		if (i==100000000)
		{
			//
			pthread_cond_broadcast(&condition);
			break;	

		}

	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	pthread_cond_destroy(&condition);
	pthread_mutex_destroy(&mutex);


	return 0;
}


