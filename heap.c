#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq == NULL || pq->size == 0) return NULL;
  void* top = pq->heapArray[0].data;
  return top;
}



void heap_push(Heap* pq, void* data, int priority){
    if(pq->size == pq->capac){
      pq = realloc(pq, (pq->capac*2)+1);
    }
  
  pq->heapArray[pq->size+1].data = data;
  pq->heapArray[pq->size+1].priority = priority;

  if()
}


void heap_pop(Heap* pq){

}

Heap* createHeap() {
    Heap* new = (Heap*)malloc(sizeof(Heap));

    if (new == NULL) {
        return NULL;
    }

    new->heapArray = (heapElem*)malloc(3 * sizeof(heapElem)); 

    if (new->heapArray == NULL) {
        free(new);
        return NULL; 
    }

    new->size = 0; 
    new->capac = 3;

    return new;
}