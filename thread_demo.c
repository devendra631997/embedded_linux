//link with -lpthread
#include<pthread.h>
#include<stdio.h>
void *msg(void *ptr)
{
        //pthread_t thread1, thread2;
          printf("Print Statement Thread : 1\n"); 
}
void *quotes(void *ptr)
{
        printf("Thread:2 - Hard work is key to success\n");
}
int main()
{
        pthread_t thread1, thread2;
        //printf("Hello World in Main 1");
	int ret1 = pthread_create(&thread1,NULL,msg,NULL);
        printf("Return value from Thread 1 %d\n",ret1);
	//printf("Hello World from Main\n");
        /*pthread join will keep the main in the waiting
	state until thread doesn't get terminated*/
	
	/*
	 pthread_create must be follwed by
	 pthread join or pthread_exit to keep 
	the main process in the waiting state to get
	 a deterministic output*/
	/*
		Threads runs as a indepndent
		unit so order of execution is not
		guaranteed.
	*/
	
	int ret2 = pthread_create(&thread2,NULL,quotes,NULL);
	printf("Return value from Thread2 %d\n", ret2);
        pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	//pthread_exit(NULL);
	
	return 0;
}

