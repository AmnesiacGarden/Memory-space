#include <stdio.h>

void bininsert(int a[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int mid , i;

    while(low <= high) {
        mid = (low + high)/2 ;

        if(x >= a[mid]) {
            low = mid + 1 ;            
        }
        else {
            high = mid - 1 ;
        }
    }

    for(i = n - 1 ; i >= high + 1 ; i--) {
        a[i+1] = a[i] ;
    }
    a[high+1] = x ;
}

void insertsort(int a[],int n) {
    int i;
    for(i = 1 ; i < n ; i++) {
        bininsert(a, i, a[i]) ;
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


