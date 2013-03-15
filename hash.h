#include <stdlib.h>
#include <stdio.h>
#include "linkedvars.h"

/*
 * Structure of a hasmap
 */
struct hashmap_{
  varlist** bucket;
  int bucketsize;
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
 * Determine bucket number for variable name in a map
 */
int hm_which_bucket(hashmap* map, char* var) {
  return ((int)var[0]-32) % map->bucketsize;
}



int hm_insert(hashmap* map, char* var, double value) {
  vl_insert( map->bucket[hm_which_bucket(map, var)], var, value);
}
