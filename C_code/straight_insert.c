#include <stdio.h>

void insert(int a[], int n, int x) {
    int k;
    for(k = n-1 ; k >= 0 && a[k] > x ; k--) {
        a[k+1] = a[k] ;
    }
    a[k+1] = x ;
}

void insertsort(int a[],int n) {
    int i;
    for(i = 1 ; i < n ; i++) {
        insert(a, i, a[i]) ;
    }
}

#define N 10

int main() {
    int a[N] , i;
    for(i = 0 ; i < N ; i++) {
        scanf("%d",&a[i]) ;
    }

    insertsort(a, N);

    for(i = 0 ; i < N ; i++) {
        printf("%2d",a[i]) ;
    }
    printf("\n") ;
    return 0;
}