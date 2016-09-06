#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
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
 struct pq *my_pq = malloc(sizeof (struct pq));
 my_pq->front = NULL;
 my_pq->back = NULL;
 return my_pq;
}

// see pq.h for details
void pq_destroy(struct pq *pqueue) {
 struct llnode *curnode = pqueue->front;
 while(curnode)
 {
  struct llnode *nextnode = curnode->next;
  free(curnode);
  curnode = nextnode;
 }
 free(pqueue);
}

// see pq.h for details
void pq_add(struct pq *pqueue, int item, int priority) {
 assert(pqueue);
 assert(priority > 0);
 if((pqueue->front==NULL)||(priority<pqueue->front->priority)) 
 {
  struct llnode *node = malloc(sizeof (struct llnode));
  node->item = item;
  node->priority = priority;
  node->next = pqueue->front;
  pqueue->front = node;
 }
 else 
 {
  struct llnode *prevnode = pqueue->front;
  while(((prevnode->next)&&
         ((priority>prevnode->next->priority)||
          ((priority==prevnode->next->priority)&&
           (item>prevnode->next->item)))))
  {
   prevnode = prevnode->next;
  }
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = item;
  newnode->priority = priority;
  newnode->next = prevnode->next;
  prevnode->next = newnode;
 }
}

// see pq.h for details
int pq_remove(struct pq *pqueue) {
 assert(pqueue);
 assert(pqueue->front);
 int retvalue = pqueue->front->item;
 struct llnode *backup = pqueue->front;
 pqueue->front = pqueue->front->next;
 free(backup);
 if(pqueue->front == NULL)
 {
  pqueue->back = NULL;
 }
 return retvalue;
}

// see pq.h for details
bool pq_is_empty(const struct pq *pqueue){
 return (pqueue->front == NULL);
}

// see pq.h for details
void pq_print(const struct pq *pqueue) {
 assert(pqueue);
 struct llnode *node = pqueue->front;
 while(node)
 {
  printf("[%d] %d", node->priority, node->item); 
  while((node->next)&&(node->next->priority == node->priority))
  {
   printf(" %d",node->next->item);
   node = node->next;
  }
  printf("\n");
  node = node->next;
 }
 free(node);
}

// see pq.h for details
int pq_length(const struct pq *pqueue) {
 assert(pqueue);
 int len = 0;
 struct llnode *node = pqueue->front;
 while(node) 
 {
  ++len;
  node = node->next;
 }
 return len;
}

// see pq.h for details
int pq_front_priority(const struct pq *pqueue) {
 assert(pqueue);
 assert(pqueue->front);
 return pqueue->front->priority;
}

// see pq.h for details
int pq_front_item(const struct pq *pqueue) {
 assert(pqueue);
 assert(pqueue->front);
 return pqueue->front->item;
}