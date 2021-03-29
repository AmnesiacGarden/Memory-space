#include <stdio.h>

typedef int ElemType;

void swap(ElemType *p, ElemType *s) {
    ElemType t;
    t = *p ;
    *p = *s ;
    *s = t ;
}

void Qsort(ElemType A[], int left, int right) {
    if(left > right) {
        return ;
    }

    ElemType pivot = A[right] ;
    int i = left ;
    int j = right - 1 ;

    for(;;) {
        while(A[i] < pivot) i++ ;
        while(j >= 0 && A[j] >= pivot) j-- ;
        if(i < j) {
            swap(&A[i], &A[j]);
        }
        else {
            break;
        }
    }

    swap(&A[i], &A[right]);
    Qsort(A, left, i-1);
    Qsort(A, i+1, right);
}

void Quicksort(ElemType A[], int n) {
    Qsort(A, 0, n-1);
}

#define N 10

int main() {
    int a[N] , i;
    for(i = 0 ; i < N ; i++) {
        scanf("%d",&a[i]) ;
    }

    Quicksort(a, N);

    for(i = 0 ; i < N ; i++) {
        printf("%2d",a[i]) ;
    }
    printf("\n") ;
    return 0;
}

