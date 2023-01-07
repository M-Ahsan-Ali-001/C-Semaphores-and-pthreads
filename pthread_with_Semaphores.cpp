#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;

int shared_x=1;
    sem_t sem;
void *thread_1( void * args)
{
       sem_wait(&sem);
    //sleep(1);
    shared_x++;
    cout<<"\nThread_1\n";
    cout<<"Value of X is "<<shared_x;
        sem_post(&sem);
     return 0;   
}
void *thread_2( void * args)
{
       sem_wait(&sem);
    
    shared_x--;
    cout<<"\nThread_2\n";
    cout<<"Value of X is "<<shared_x;

   sem_post(&sem);
    return 0;
}
 
int main()
{
 
    int maxThreads=2;
    pthread_t threads[maxThreads];
    sem_init(&sem,0,1) ;
        
    pthread_create(&threads[0],NULL,&thread_1,NULL);
        pthread_create(&threads[1],NULL,&thread_2,NULL);
      
       
    pthread_join(threads[0],NULL);
        pthread_join(threads[1],NULL);
            cout<<"\nValue of X  in main : "<<shared_x<<endl;
    
}