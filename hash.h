/* hash.h --- simple hashmap implementation for calc+
 *
 * Filename: hash.h
 * Description: simple hashmap implementation for calc+
 * Author: Jordon Biondo
 * Maintainer:
 * Created: Fri Mar 15 00:38:36 2013 (-0400)
 * Version: .1
 * Last-Updated: Fri Mar 15 00:38:43 2013 (-0400)
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
#include "linkedvars.h"


/*
 * Structure of a hasmap
 */
struct hashmap_{
  varlist** bucket;
  int bucketsize;
  int sought;
};


/*
 * Hashmap type
 */
typedef struct hashmap_ hashmap;


/*
 * Create a hashmap
 */
hashmap* new_hashmap(int size) {
  hashmap* map = malloc(sizeof(hashmap));
  map->bucket = malloc(sizeof(varlist*) * size);
  map->bucketsize = size;
  int i;
  for (i = 0; i < size; i++) {
    map->bucket[i] = new_varlist();
  }
  return map;
}


/*
 * Get the bucket number that would contain VAR
 */
int hm_which_bucket(hashmap* map, char* var) {
  return ((int)var[0]-32) % map->bucketsize;
}



/*
 * Get the varlist that would contain VAR
 */
varlist* hm_get_bucket(hashmap* map, char* var) {
  return map->bucket[hm_which_bucket(map, var)];
}



/*
 * Insert VAR, VALUE pair into map
 * Does not check preexistence
 */
int hm_insert(hashmap* map, char* var, double value) {
  vl_insert( hm_get_bucket(map, var), var, value);
}


/*
 * Return true if MAP contains var,
 * false if not.
 * If found, sought is set to VAR's value
 */
bool hm_find(hashmap* map, char* var) {
  varlist* list = hm_get_bucket(map, var);
  if(vl_search_by_var(list, var)) {
    map->sought = list->sought->value;
    return true;
  } else {
    return false;
  }
}

/* hash.h ends here */
