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
  int value;
  struct node_* next;
};


/*
 * Node type
 */
typedef struct node_ node;



/*
 * Create a new node
 */
node* new_node(char* var, int value) {
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


varlist* vl_new(void);
void vl_put(varlist*, char*, int);
bool vl_search_by_var(varlist*, char*);

/*
 * Create a new linked list.
 */
varlist* vl_new(void) {
  varlist* list = malloc(sizeof(varlist));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}


/*
 * Put a var|value pair node on the list
 * if there is a VAR node, update it
 * - This is more of a linked set, than a linked list
 */
void vl_put(varlist* list, char* var, int value) {
  if(vl_search_by_var(list, var)) {
    list->sought->value = value;
  } else {
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
    printf("\t{%s=%d}\n", n->var, n->value); 
    n = n->next;
  }
  printf("--end dump\n");
}


  

/* linkedvars.h ends here */
