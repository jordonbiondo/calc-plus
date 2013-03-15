/* linkedvars.h --- linked list implementation for calc+
 *  
 * Filename: linkedvars.h
 * Description: linked list implementation for calc+
 * Author: Jordon Biondo
 * Maintainer: 
 * Created: Fri Mar 15 00:41:01 2013 (-0400)
 * Version: 
 * Last-Updated: Fri Mar 15 00:41:15 2013 (-0400)
 *           By: Jordon Biondo
 *     Update #: 1
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* Code: */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
 * Structure of a node
 */
struct node_{
  char* var;
  double value;
  struct node_* next;
};


/*
 * Node type
 */
typedef struct node_ node;



/*
 * Create a new node
 */
node* new_node(char* var, double value) {
  node* n = malloc(sizeof(node));
  n->var = var;
  n->value = value;
  return n;
}


/*
 * Structure of a linked list
 */
struct varlist_ {
  node* first;
  node* last;
  node* sought;
  int length;

};

/*
 * var List type
 */
typedef struct varlist_ varlist;



/*
 * Create a new linked list.
 */
varlist* new_varlist(void) {
  varlist* list = malloc(sizeof(varlist));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}


/*
 * Insert a new node into a var list.
 */
void vl_insert(varlist* list, char* var, double value) {
  node* n = new_node(var, value);
  if(list->first == NULL) {
    list->first = n;
    list->last = n;
  } else {
    list->last->next = n;
    list->last = n;
  }
  list->length++;
}

bool vl_search_by_var(varlist* list, char* var) {
  node* n = list->first;
  while(n) {
    if (!strcmp(var, n->var)) {
      list->sought = n;
      return true; 
    }
    n = n->next;
  }
  return false;
}



/*
 * Dump the values of the var list to stdout.
 */
void vl_dump(varlist* list) {
  node* n = list->first;
  printf("--dumping varlist length=%d\n", list->length);
  while (n) {
    printf("\t{%s=%.2f}\n", n->var, n->value);
    n = n->next;
  }
  printf("--end dump\n");
}


  

/* linkedvars.h ends here */
