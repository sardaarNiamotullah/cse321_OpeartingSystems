#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>

#define MAX 10              //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2         //number of threads

char buffer[BUFLEN];
char source[BUFLEN];        //from this array producer will store it's production into buffer

int pCount = 0;
int cCount = 0;
int buflen;
int count = 0;

sem_t semEmpty;
sem_t semFull;

pthread_mutex_t mutexBuffer;

void* producer(int *id) {
    
    while (1) {
        if (pCount > MAX) break;

        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        buffer[count] = source[count];
        count++;
        printf("%d produced %c by Thread 0\n", pCount, source[count]);
        pCount++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

void* consumer(int *id) {
    while (1) {
        if (cCount > MAX) break;

        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        char y = buffer[count - 1];
        count--;
        printf("%d consumed %c by Thread 1\n", cCount, y);
        cCount++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);
    }
}

int main() {
    strcpy(source, "abcdef");
    buflen = strlen(source);

    pthread_t thread[NUMTHREAD];
    pthread_mutex_init(&mutexBuffer, NULL);
    sem_init(&semEmpty, 0, 5);
    sem_init(&semFull, 0, 0);

    pthread_create(&thread[0], NULL, &producer, NULL);
    pthread_create(&thread[1], NULL, &consumer, NULL);
    
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);

    return 0;
}