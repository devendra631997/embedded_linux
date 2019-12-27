#include<stdio.h>
#include<pthread.h>
int counter = 0;
pthread_mutex_t lock;
void *count1(void *pv)
{
	pthread_mutex_lock(&lock);
	int i;
	counter++;
	printf("Count1 start: The value of counter = %d\n",counter);
	for(i=0;i<0xffffffff;i++);
	printf("count1 end : the value of counter = %d\n",counter);
	pthread_mutex_unlock(&lock);	
}
void *count2(void *pv)
{
        pthread_mutex_lock(&lock);
	int i;
	counter++;
        printf("Count2 start: The value of counter = %d\n",counter);
        for(i=0;i<0xffffffff;i++);
        printf("count2 end : the value of counter = %d\n",counter);
	pthread_mutex_unlock(&lock);
}
int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, count1, NULL);
	pthread_create(&t2, NULL, count2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}





