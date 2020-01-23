#include <pthread.h>
#include <stdio.h>

int i = 0;

pthread_mutex_t mutex;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    int k;
    for (k = 0; k < 1000000; k++)
    {
        while(pthread_mutex_trylock(&mutex)!= 0)
        {
        }
        i++;
        pthread_mutex_unlock(&mutex);
    }


    return NULL;
}

void* decrementingThreadFunction(){
    int k;
    for (k = 0; k < 1000000; k++)
    {
        while(pthread_mutex_trylock(&mutex) != 0)
        {}
        i--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(){

    pthread_t incrementingThread;
    pthread_t decrementingThread;
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)

    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);

    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

    printf("The magic number is: %d\n", i);
    return 0;
}