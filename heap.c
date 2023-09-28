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
  if (pq->size == pq->capac) {
    pq->capac = (pq->capac * 2) + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if (pq->heapArray == NULL) {
      return;
    }
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;
  
  int indice = pq->size - 1;

  while (indice > 0) {
    int anterior = (indice-1)/2;
    if (pq->heapArray[indice].priority > pq->heapArray[anterior].priority) {
            heapElem temp = pq->heapArray[indice];
            pq->heapArray[indice] = pq->heapArray[anterior];
            pq->heapArray[anterior] = temp;

            indice = anterior;
        } else {
            break; 
        }
    }
}

void heap_pop(Heap* pq) {
    if (pq == NULL || pq->size == 0) {
        return; 
    }

    pq->heapArray[0] = pq->heapArray[pq->size - 1];
    pq->size--;

    int indice = 0;
    while (1) {
        int hijoIzq = 2 * indice + 1;
        int hijoDer = 2 * indice + 2;
        int grande = indice;

        if (hijoIzq < pq->size && pq->heapArray[hijoIzq].priority > pq->heapArray[grande].priority) {
            grande = hijoIzq;
        }

        if (hijoDer < pq->size && pq->heapArray[hijoDer].priority > pq->heapArray[grande].priority) {
            grande = hijoDer;
        }

        if (grande != indice) {
            heapElem temp = pq->heapArray[indice];
            pq->heapArray[indice] = pq->heapArray[grande];
            pq->heapArray[grande] = temp;
            indice = grande;
        } else {
            break;
        }
    }
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