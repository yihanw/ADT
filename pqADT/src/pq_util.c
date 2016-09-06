#include <assert.h>
#include <stdlib.h>
#include "pq.h"
#include "pq_util.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Yihan Wang
// login ID: y2349wan

// implementation:

// see pq_util.h for details
void to_array(struct pq *pqueue, int **arr_ptr, int *len) {
 assert(pqueue);
 struct llnode *node = pqueue->front;
 int pri_count = 0;
 while(node)
 {
  if((node->next)&&(node->priority==node->next->priority))
  {
   pri_count++;
  }
  node=node->next;
 }//while loop
 free(node);
 int *pri_len = malloc(pri_count*(sizeof(int)));
 struct llnode *node2 = pqueue->front;
 int i = 0;
 while(node2)
 {
  if((node2->next)&&(node2->priority==node2->next->priority))
  {
   pri_len[i]+=1;
  }
  else {
   ++i;
  }
  node2 = node2->next;
 }//while loop
 struct llnode *node3 = pqueue->front;
 for(int i=0; i<pri_count; ++i) 
 {
  pri_len[i]+=1;
 }
 for(int j=0; j<pri_count; ++j)
 {
  *arr_ptr=malloc(pri_len[j]*(sizeof(int)));
  for(int k=0; k<pri_len[j]; ++k)
  {
   arr_ptr[j][k]=node3->item;
   node3=node3->next;
  }
  free(*arr_ptr);
 }
 free(pri_len);
}

struct pq **k_way_split(struct pq *pqueue, const int k){
 struct pq **pq_lst=malloc((k-1)*(sizeof(struct pq))); 
 int len = pq_length(pqueue);
 for(int i=0; i<len; i++)
 {
  for(int j=0; j<k; j++)
  {
   pq_add(pq_lst[i%k], pq_front_item(pqueue), pq_front_priority(pqueue));
  }
 }
 return pq_lst;
}
 
