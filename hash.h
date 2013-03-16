/* hash.h --- simple hashmap implementation for calc+
 *
 * Filename: hash.h
 * Description: simple hashmap implementation for calc+
 * Author: Jordon Biondo
 * Maintainer: Jordon Biondo
 * Created: Fri Mar 15 00:38:36 2013 (-0400)
 * Version: .1
 * Last-Updated: Fri Mar 15 10:33:20 2013 (-0400)
 *           By: Jordon Biondo
 *     Update #: 9  
 *
 */

/* Code: */


#include <stdlib.h>
#include <stdio.h>
#include "linkedvars.h"

#define DEFAULT_HASHMAP_SIZE 20

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
hashmap* hm_new(int size) {
  hashmap* map = malloc(sizeof(hashmap));
  map->bucket = malloc(sizeof(varlist*) * size);
  map->bucketsize = size;
  int i;
  for (i = 0; i < size; i++) {
    map->bucket[i] = vl_new();
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
 * Put a var|value pair in the map, 
 * if var exists, set new value
 */
int hm_put(hashmap* map, char* var, int value) {
  vl_put(hm_get_bucket(map, var), var, value);
}


/*
 * Return true if MAP contains entry for VAR, false if not
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
