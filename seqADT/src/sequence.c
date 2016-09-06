#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "sequence.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Yihan Wang
// login ID: y2349wan

// implementation:

// see sequence.h for details
struct Sequence *Sequence_create(void) {
 struct Sequence *s = malloc(sizeof (struct Sequence));
 s->front = NULL;
 return s;
}

// see sequence.h for details
void Sequence_destroy(struct Sequence *seq) {
 struct llnode *curnode = seq->front;
 while(curnode)
 {
  struct llnode *nextnode = curnode->next;
  free(curnode);
  curnode = nextnode;
 }
 free(seq);
}

// see sequence.h for details
int Sequence_length(const struct Sequence *seq) {
 int len = 0;
 struct llnode *node = seq->front;
 while(node) 
 {
  len+=1;
  node = node->next;
 }
 return len;
}

// see sequence.h for details
int Sequence_item_at(const struct Sequence *seq, int pos) {
 assert((pos >= 0)&&(pos < Sequence_length(seq)));
 struct llnode *node = seq->front;
 while(node) 
 {
  if(node->pos == pos) {
   return node->item;
  }
  else {
   node = node->next;
  }
 }
 return 0;
}

// see sequence.h for details
void Sequence_insert_at(struct Sequence *seq, int pos, int val) {
 assert((pos >= 0)&&(pos <= Sequence_length(seq)));
 if(pos == 0) {
  struct llnode *node = malloc(sizeof (struct llnode));
  node->item = val;
  node->pos = pos;
  node->next = seq->front;
  seq->front = node;
  struct llnode *curnode = seq->front;
  while(curnode->next) 
  {
   curnode->next->pos += 1;
   curnode = curnode->next;
  }
 }//if
 else {
  struct llnode *prevnode = seq->front;
  while(prevnode->pos < (pos-1)) 
  {
   prevnode = prevnode->next;
  }
  struct llnode *newnode = malloc(sizeof(struct llnode));
  newnode->item = val;
  newnode->pos = pos;
  newnode->next = prevnode->next;
  prevnode->next = newnode;
  while(prevnode->next->next) 
  {
   prevnode->next->next->pos += 1;
   prevnode = prevnode->next;
  }
 }//else
}

// see sequence.h for details
int Sequence_remove_at(struct Sequence *seq, int pos) {
 assert((pos >= 0)&&(pos <= Sequence_length(seq)));
 int retvalue = 0; 
 if(pos == 0)
 {
  retvalue = seq->front->item;
  struct llnode *backup = seq->front;
  seq->front = seq->front->next;
  free(backup);
 }//if
 else 
 {
  struct llnode *prevnode = seq->front;
  while(pos>1)
  {
   prevnode = prevnode->next;
   --pos;
  }
  retvalue = prevnode->next->item;
  struct llnode *backup = prevnode->next;
  prevnode->next = prevnode->next->next;
  free(backup);
 }//else
 return retvalue;
}

// see sequence.h for details
void Sequence_print(const struct Sequence *seq) {
 if(seq->front == NULL)
 {
  printf("[empty]\n");
 }
 else
 {
  printf("[%d]", Sequence_length(seq));
  struct llnode *node = seq->front;
  while(node)
  {
   printf(" %d", node->item);
   node = node->next;
  }
  printf("\n");
 }
}