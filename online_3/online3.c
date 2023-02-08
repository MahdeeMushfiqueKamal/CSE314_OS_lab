#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "zemaphore.h"

zem_t *zem_a;
zem_t *zem_b;
zem_t *zem_c;
zem_t *zem_x;
int num_printed = 0;

void* print_abc(void *arg){
     char ch = *(char*) arg;
     while(1){
          printf("%c\n", ch);
          getchar();
     }
}

void* print_x(void *arg){
     while(1){
          printf("X\n");
          getchar();
     }
}

int main(int argc, char const *argv[])
{
     pthread_t t1, t2, t3, t4;
     char *chptr = (char*)malloc(sizeof(char));


     *chptr = 'A';
     if( pthread_create(&t1, NULL, &print_abc, chptr) != 0){
          printf("Error while creating thread. Exiting...");
          exit(0);
     }
     *chptr = 'B';
     if( pthread_create(&t2, NULL, &print_abc, chptr) != 0){
          printf("Error while creating thread. Exiting...");
          exit(0);
     }
     *chptr = 'C';
     if( pthread_create(&t3, NULL, &print_abc, chptr) != 0){
          printf("Error while creating thread. Exiting...");
          exit(0);
     }
     if( pthread_create(&t4, NULL, &print_x, NULL) != 0){
          printf("Error while creating thread. Exiting...");
          exit(0);
     }
     

     
     if( pthread_join(t1, NULL) != 0){
          printf("Error while joining thread. Exiting...");
          exit(0);
     }    
     if( pthread_join(t2, NULL) != 0){
          printf("Error while joining thread. Exiting...");
          exit(0);
     }  
     if( pthread_join(t3, NULL) != 0){
          printf("Error while joining thread. Exiting...");
          exit(0);
     }  
     if( pthread_join(t4, NULL) != 0){
          printf("Error while joining thread. Exiting...");
          exit(0);
     }  

     return 0;
}
