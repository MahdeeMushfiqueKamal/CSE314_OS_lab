#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "zemaphore.h"

#define NUM_CHAIRS 5
#define NUM_CUSTOMERS 10

sem_t* barber;
sem_t* customer;
sem_t* mutex;
int waiting = 0;

void *barberThread(void *arg) {
  while (1) {
    sem_wait(customer);
    sem_wait(mutex);
    waiting--;
    sem_post(barber);
    sem_post(mutex);
    printf("Barber is cutting hair.\n");
    int sleeptime = rand()%3 + 1;
    sleep(sleeptime);
  }
  return NULL;
}

void *customerThread(void *arg) {
  sem_wait(mutex);
  if (waiting < NUM_CHAIRS) {
    waiting++;
    sem_post(customer);
    sem_post(mutex);
    sem_wait(barber);
    printf("Customer is getting a haircut.\n");
  } else {
    sem_post(mutex);
    printf("Customer leaves the barber shop.\n");
  }
  return NULL; 
}

int main(void) {
  barber = (sem_t*) malloc(sizeof(sem_t));
  customer = (sem_t*) malloc(sizeof(sem_t));
  mutex = (sem_t*) malloc(sizeof(sem_t));

  pthread_t barber_id;
  pthread_t customer_id[NUM_CUSTOMERS];
  sem_init(barber, 0, 0);
  sem_init(customer, 0, 0);
  sem_init(mutex, 0, 1);
  pthread_create(&barber_id, NULL, barberThread, NULL);
  for (int i = 0; i < NUM_CUSTOMERS; i++) {
    pthread_create(&customer_id[i], NULL, customerThread, NULL);
    int sleeptime = rand()%1 + 5;
    sleep(sleeptime);
  }
  pthread_join(barber_id, NULL);
  for (int i = 0; i < NUM_CUSTOMERS; i++) {
    pthread_join(customer_id[i], NULL);
  }
  sem_destroy(barber);
  sem_destroy(customer);
  sem_destroy(mutex);
  return 0;
}
