#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 20

sem_t chairs_mutex;
sem_t sem_client;
sem_t sem_barber;
int num_chairs;
int clientWait;

void *barber(void *arg) {
   int worktime;
   while(1) {
      //Wait for a client to become available (sem_client).
      sem_wait(&sem_client);
      //Wait for mutex to access chair count (chair_mutex).
	  sem_wait(&chairs_mutex);
      //Increment number of chairs available.
	  num_chairs += 1;
	  printf("Barber: Taking a client. Number of chairs available=%d\n",num_chairs);
      //Signal to client that barber is ready to cut their hair (sem_barber).
	  sem_post(&sem_barber);
      //Unlock chair.
	  sem_post(&chairs_mutex);
      //Generate random worktime (duration of a haricut), from 1-4 seconds.
	  worktime=(rand() % 4) + 1;
      //Cut hair for worktime seconds.
          printf("Barber: Cutting hair for %d seconds\n", worktime);
	  sleep(worktime);
    } 
}

void *client(void *arg) {
   int waittime;

   while(1) {
      //Wait for mutex to access chair count (chair_mutex).
	  sem_wait(&chairs_mutex);

	  if(num_chairs <= 0){
           //Free mutex lock on chair count.
		   printf("Client: Thread %u leaving with no haircut\n", (unsigned int)pthread_self());
		   sem_post(&chairs_mutex);
	  }
     	  else{
                   num_chairs -= 1;
		   printf("Client: Thread %u sitting to wait. Number of chairs left=%d\n",(unsigned int)pthread_self(),num_chairs);
           //Signal that a customer is ready (sem_client).
		   sem_post(&sem_client);
           //Free mutex lock on chair count.
		   sem_post(&chairs_mutex);
           //Waiting for barber (sem_barber).
		   sem_wait(&sem_barber);
           //Getting haircut.
		   printf("Client: Thread %u getting a haircut\n",(unsigned int)pthread_self());
	  }
	 /* generate random number, waittime, for length of wait until next haircut or next try.  Max value from command line. */
	  waittime=(rand() % clientWait) + 1;
      /* sleep for waittime seconds */
	  printf("Client: Thread %u waiting %d seconds before attempting next haircut\n",(unsigned int)pthread_self(),waittime);
	  sleep(waittime);
     }
}

int main(int argc, char *argv[]) {
	pthread_t barberid;
	pthread_t clientids[MAX];
	
	printf("Main thread beginning\n");

   //Verifying and initialising command line arguments.
   int runTime, clients, i;
   if (argc != 5){
	   printf("Please enter 4 arguments: <Program run time> <Number of clients>\n");
	   printf("<Number of chairs> <Client wait time>\n");
	   exit(0);
   }
   runTime=atoi(argv[1]);
   clients=atoi(argv[2]);
   num_chairs=atoi(argv[3]);
   clientWait=atoi(argv[4]);

   //Initializing semaphores.
   sem_init(&chairs_mutex,0,1);
   sem_init(&sem_client,0,0);
   sem_init(&sem_barber,0,0);

   //Creating barber thread.
   pthread_create(&barberid, NULL, barber, NULL);
   printf("Barber thread created with ID: %lu\n",barberid);
   
   //Creating client threads.
   for (i=0; i < clients; i++){
	   pthread_create(&clientids[i], NULL, client, NULL);
	   printf("Client thread created with ID: %lu\n",clientids[i]);
   }
   
   //Sleep till job is done and then exit.
   printf("Main thread sleeping for %d seconds\n", runTime);
   sleep(runTime);
   printf("Main thread exiting\n");
   exit(0);
}
