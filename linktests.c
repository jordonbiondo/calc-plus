#include <stdlib.h>
#include <stdio.h>
#include "hash.h"



int main(void) {
  
  /*
   * Some crappy varlist tests
   */
  varlist* list = new_varlist();
  printf("asdf\n");
  vl_insert(list, "hello", 10);
  vl_insert(list, "bacon", 12);
  printf("asdf\n");
  vl_dump(list);


  /*
   * Hashmap initialization
   */
  hashmap* map = new_hashmap(10);
  printf("%d\n", map->bucketsize);
  int i = 0;
  for (i = 0; i < map->bucketsize; i++) {
    vl_dump (map->bucket[i]);
  }
  hm_insert(map, "asdf", 10);
  hm_insert(map, "apple", 10);
  hm_insert(map, "Jordon", 400);
  for (i = 0; i < map->bucketsize; i++) {
    vl_dump (map->bucket[i]);
  }
  
  
  
}
