/*
 sequence.c
 Sequence ADT Implementation
*/
// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Yihan Wang
// login ID: y2349wan

// implementation:
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "sequence.h"

void Seq_init(struct Sequence *s) {
 assert(s);
 s->max_len = 100;
 s->length = 0;
}

int Sequence_length(const struct Sequence *seq){
 assert(seq);
 return seq->length;
}

void Sequence_clear(struct Sequence *seq) {
 assert(seq);
 for (int i=0; i<seq->length; ++i) 
 {
  seq->arr[i] = 0;
 }
 seq->length = 0;
}

int Sequence_item_at(const struct Sequence *seq, int pos) {
 assert(seq);
 assert((pos >= 0) && (pos < seq->length));
 return seq->arr[pos];
}

void Sequence_insert_at(struct Sequence *seq, int pos, int val){
 assert(seq);
 assert((pos >= 0) && (pos <= seq->length));
 if (seq->max_len == seq->length) {
  printf("Sequence Filled: max length is %d items.\n", seq->max_len);
 }
 int temp_len = seq->length - pos;
 int temp [temp_len];
 for (int i=0; i<temp_len; ++i) 
 {
  temp[i] = seq->arr[i+pos];
 }
 int j = 0; 
 seq->length += 1;
 for (int i=0; i<seq->length; ++i) 
 {
  if (i<pos) {}
  else if (i == pos) {
   seq->arr[i] = val;
  }
  else {
   seq->arr[i] = temp[j];
   ++j;
  }
 }
}

int Sequence_remove_at(struct Sequence *seq, int pos) {
 assert(seq);
 assert((pos >= 0) && (pos < seq->length));
 int value = 0;
 for (int i=0; i<seq->length; ++i) 
 {
  if (i<pos) {}
  else if (i == pos) {
   value = seq->arr[i];
   seq->arr[i] = seq->arr[i+1];
  }
  else {
   seq->arr[i] = seq->arr[i+1];
  }
 }
 seq->length -= 1;
 return value;
}

void Sequence_print(const struct Sequence *seq){
 assert (seq);
 if (seq->length == 0) {
  printf("[empty]\n");
 }
 else {
  printf("[%d]", seq->length);
  for (int i=0; i<seq->length; ++i) 
  {
   printf(" %d", seq->arr[i]);
  }
  printf("\n");
 }
}
