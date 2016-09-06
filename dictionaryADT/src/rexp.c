#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#include "rexp.h"

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Yihan Wang
// login ID: y2349wan

// implementation:
int pos = 0;  

struct enode *string_to_enode(struct enode *node, const char *s){
 char c;
 if(sscanf(s+pos,"%c", &c)==1){
  if(c == '+'||c == '-'||c == '*'||c == '/'){
   node->type = c;
   pos++;
   string_to_enode(node->left, s);
   string_to_enode(node->right, s);
  }
  else if(c >= 48 && c <= 57){
   node->type = 'n';
   node->number = c - 48;
  }
  else{
   pos++;
   string_to_enode(node, s);
  }
 }
 return node;
}

// see rexp.h for details
struct rexp *string_to_rexp(const char *s) {
 struct enode *node = malloc(sizeof(struct enode));
 node = string_to_enode(node, s);
 struct rexp *r = malloc(sizeof(struct rexp));
 r->root = node;
 return r;
 free(node);
}

// see rexp.h for details
int rexp_eval(const struct rexp *r, const struct dictionary *constants) {
  return 0;
}

void enode_destroy(struct enode *node){
 if(node){
  if(node->type == 'n'){
   free(node->left);
   free(node->right);
  }
  free(node);
 }
}

// see rexp.h for details
void rexp_destroy(struct rexp *r) {
 struct enode *node = r->root;
 enode_destroy(node);
 free(r);
}


void add_constant(const char *s, struct dictionary *constants) {
}


///////////////////////////////////////////////////////////////////////
// do NOT modify these functions: they are used for marmoset testing //
// (you may find them useful for your own testing)                   //
///////////////////////////////////////////////////////////////////////

void print_enode(const struct enode *e) {
  assert(e);
  if (e->type == 'n') {
    printf("%d", e->number);
  } else if (e->type == 'v') {
    printf("%s", e->id);
  } else {
    printf("(%c ", e->type);
    print_enode(e->left);
    printf(" ");
    print_enode(e->right);
    printf(")");
  }
}

void print_rexp(const struct rexp *r) {
  assert(r);
  print_enode(r->root);
  printf("\n");
}
