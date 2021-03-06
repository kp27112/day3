
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>


pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
bool s = 1;

void* foo(void* a)
{
	pthread_cond_t* c  = (pthread_cond_t*)a;
	pthread_mutex_lock(&mtx);
	pthread_cond_wait(c,&mtx);

	printf("Woked up");
	pthread_mutex_unlock(&mtx);
}



int main(int c, char* v)
{
	pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

	pthread_t t_id;
	pthread_create(&t_id,0,foo,&c);
	//sleep(2);

	thread_mutex_lock(&mtx);

	//sleep=0;

	printf("Wakening");

	pthread_cond_signal(&c);
	pthread_mutex_unlock(&mtx);

	pthread_join(&t_id,0);

return 0;
}

