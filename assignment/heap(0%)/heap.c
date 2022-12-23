#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

// Create an empty heap
heapType* createHeap(void) {
  heapType* h = (heapType*)malloc(sizeof(heapType));
  h->heap_size = 0;
  return h;
}

// Insert node that has item to heap
void push(heapType* h, int item) {
    int n = h->heap_size; //n=0
    h->heap_size = h->heap_size+1 ;
    
    if (n == sizeof(heapType))
        printf("Heap is Full!\n");
    
    n = n+1;
    int i = n;
    while (1)
    {
        if (i==1)
            break;
        if (item <= h->heap[i/2])
            break;
        else
            h->heap[i] = h->heap[i/2];
        i = i/2;
        
    }
    h->heap[i] = item;
}

// Return root
int top(heapType* h) {
    return h->heap[1];
}

// Remove root
void pop(heapType* h) {
    int n = h->heap_size; 
    if (n==0)
        printf("IS ERROR!\n");
    //int item = h->heap[1]; //루트노드
    int temp = h->heap[n]; //마지막 노드
    n = n-1; //마지막 노드 삭제
    int i=1, j=2;
    
    while (j<=n){
        if (j<n)
        {
            if (h->heap[j] < h->heap[j+1])
                j = j+1;
        }
        if (temp >= h->heap[j])
            break;
        else
        {
            h->heap[i] = h->heap[j];
            i = j;
            j = j*2;
        }
    }
    h->heap[i] = temp;
    h->heap_size = h->heap_size-1;
}

// Print
void print(heapType* h) {
    for (int i=1; i<=size(h); i++)
        printf("%d ",h->heap[i]);
    printf("\n");
}

// Return number of elements
int size(heapType* h) {
    return h->heap_size;
}
