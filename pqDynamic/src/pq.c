#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "pq.h"
// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Yihan Wang
// login ID: y2349wan

// implementation:
// see pq.h for details
struct pq *pq_create(void){
 struct pq *pqueue = malloc(sizeof (struct pq));
 pqueue->size = 0;
 pqueue->item = malloc(pqueue->size*(sizeof(int)));
 pqueue->priority = malloc(pqueue->size*(sizeof(int)));
 return pqueue;
} 
 
// see pq.h for details
void pq_destroy(struct pq *pqueue){
 free(pqueue->item);
 free(pqueue->priority);
 pqueue->size = 0;
 free(pqueue);
}

// see pq.h for details
void pq_add(struct pq *pqueue, int item, int priority){
 assert(pqueue);
 assert(priority > 0);
 int i = pqueue->size;
 pqueue->size++;
 pqueue->item = realloc(pqueue->item, pqueue->size*(sizeof(int)));
 pqueue->priority = realloc(pqueue->priority, pqueue->size*(sizeof(int)));
 pqueue->item[i] = item;
 pqueue->priority[i] = priority;
  while(priority < pqueue->priority[(i-1)/2])
  {
   pqueue->item[i] = pqueue->item[(i-1)/2];
   pqueue->priority[i] = pqueue->priority[(i-1)/2];
   i = (i-1)/2;
   if(i == 0) break;
  }
 pqueue->item[i] = item;
 pqueue->priority[i] = priority;
}

// see pq.h for details
int pq_remove(struct pq *pqueue){
 assert(pqueue);
 assert(pqueue->priority||pqueue->item);
 int retval = pqueue->item[0];
 pqueue->item[0] = pqueue->item[--pqueue->size];
 pqueue->priority[0] = pqueue->priority[--pqueue->size];
 int priority = pqueue->priority[0];
 int item = pqueue->item[0];
 if(pqueue->size == 0)
 {
  pqueue->item = NULL;
  pqueue->priority = NULL;
  return retval;
 }
 int i = 0;
 while(i < pqueue->size)
 {
  if(priority > pqueue->priority[2*i+1] &&
    pqueue->priority[2*i+1] < pqueue->priority[2*i+2]){
   pqueue->priority[i] = pqueue->priority[2*i+1];
   pqueue->item[i] = pqueue->item[2*i+1];
   i = 2*i+1;
   if(i>=pqueue->size) break;
  }
  else if(priority > pqueue->priority[2*i+2] &&
    pqueue->priority[2*i+2] < pqueue->priority[2*i+1]){
   pqueue->priority[i] = pqueue->priority[2*i+2];
   pqueue->item[i] = pqueue->item[2*i+2];
   i = 2*i+2;
   if(i>=pqueue->size) break;
  }
  else break;
 }
 pqueue->item[i] = item;
 pqueue->priority[i] = priority;
 pqueue->size--;
 pqueue->item = realloc(pqueue->item, pqueue->size*(sizeof(int)));
 pqueue->priority = realloc(pqueue->priority, pqueue->size*(sizeof(int)));
 return retval;
}

// see pq.h for details
bool pq_is_empty(const struct pq *pqueue){
 assert(pqueue);
 return pqueue->priority;
}
 
// see pq.h for details
void pq_print(const struct pq *pqueue){
 assert(pqueue);
 if(pqueue->priority == NULL){
  printf("[]\n");
 }
 else{
  int len = pqueue->size;
  printf("[(%d,%d)", pqueue->item[0], pqueue->priority[0]);
  for(int i=1; i<len; ++i)
  {
   printf(",(%d,%d)",pqueue->item[i], pqueue->priority[i]);
  }
  printf("]\n");
 }
}

// see pq.h for details
int pq_length(const struct pq *pqueue){
 assert(pqueue);
 return pqueue->size;
}     

// see pq.h for details
int pq_front_priority(const struct pq *pqueue){
 assert(pqueue);
 assert(pqueue->item);
 assert(pqueue->priority);
 return pqueue->priority[0];
}

// see pq.h for details
int pq_front_item(const struct pq *pqueue){
 assert(pqueue);
 assert(pqueue->item);
 assert(pqueue->priority);
 return pqueue->item[0];
}