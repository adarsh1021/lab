#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

#define buffersize 10

pthread_mutex_t mutex;
pthread_t tidP[20],tidC[20];
sem_t full,empty;
int counter;
int buffer[buffersize];

void initialize()
{
        pthread_mutex_init(&mutex,NULL);
        // full = 0
        sem_init(&full,1,0);
        // empty = n
        sem_init(&empty,1,buffersize);
        counter=0;
}
void write(int item)
{
        buffer[counter++]=item;
}
int read()
{
        return(buffer[--counter]);
}
void *producer (void * param)
{
        int item;
        // produce item from 0 - 10
        item=rand()%10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        printf("\nProducer has produced item: %d\n",item);
        write(item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
}
void *consumer (void * param)
{
        int item;
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item=read();
        printf("\nConsumer has consumed item: %d\n",item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
}
int main()
{
        int producers, consumers, i;
        initialize();
        printf("\nEnter the no of producers: ");
        scanf("%d",&producers);
        printf("\nEnter the no of consumers: ");
        scanf("%d",&consumers);
        // produce
        for(i=0;i<producers;i++) {
                printf("\nProducer %d", i+1);
                pthread_create(&tidP[i],NULL,producer,NULL);
        }
        // consume
        for(i=0;i<consumers;i++) {
                printf("\nConsumer %d", i+1);
                pthread_create(&tidC[i],NULL,consumer,NULL);
        }
        // wait for the threads to finish
        for(i=0;i<producers;i++)
                pthread_join(tidP[i],NULL);
        for(i=0;i<consumers;i++)
                pthread_join(tidC[i],NULL);
        // sleep(3);
        exit(0);
}

