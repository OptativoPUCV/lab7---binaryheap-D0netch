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
  if(pq == NULL) return NULL;
  void* top = pq->heapArray->priority;
  return top;
}



void heap_push(Heap* pq, void* data, int priority){

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