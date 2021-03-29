#include <stdio.h>

void bubble_sort(int a[], int n) {
    int i,tmp;
    int t = 0;

    for(t = 0 ; t < n - 1 ; t++) {
        for(i = 0 ; i < n - 1 - t ; i++) {
            if(a[i] > a[i+1]) {
                tmp = a[i] ;
                a[i] = a[i+1] ;
                a[i+1] = tmp ;
            }
        }
    }
}

#define N 10

int main() {
    int a[N] , i;
    for(i = 0 ; i < N ; i++) {
        scanf("%d",&a[i]) ;
    }

    bubble_sort(a, N);

    for(i = 0 ; i < N ; i++) {
        printf("%2d",a[i]) ;
    }
    printf("\n") ;
    return 0;
}

