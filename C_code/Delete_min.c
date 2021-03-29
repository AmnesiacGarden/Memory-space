#include <stdio.h>
#include <stdlib,h>

typedef int ElemType;

typedef strust HeapStrust{
    int Capacity;
    int Size;

    ElemType *Elements;
}HeapStrust;

void Insert_MinHeap(HeapStrust *H, ElemType X) {
    int i;
    for(i = ++H->Size ; H -> Elements[i/2] > X ; i = i / 2) {
        H->Elements[i] = H->Elements[i/2] ;
    }
    H->Elements[i] = X ;
}

Elements Delete_Min(HeapStrust *H) {
    
}