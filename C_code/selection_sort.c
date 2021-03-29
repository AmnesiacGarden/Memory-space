#include <stdio.h>

void swap(int *p, int *s) {
    int t = *p ;
    *p = *s ;
    *s = t ;
}

void selection_sort(int a[], int n) {
    int i, t, min;

    for(t = 0; t < n - 1 ; t++) {
        min = t ;

        for(i = t + 1 ; i < n ; i++){
            if(a[i] < a[min]) {
                min = i ;
            }
        }
        if(t != min) {
            swap(&a[t], &a[min]);
        }
    }
}

#define N 10

int main() {
    int a[N] , i;
    for(i = 0 ; i < N ; i++) {
        scanf("%d",&a[i]) ;
    }

    selection_sort(a, N);

    for(i = 0 ; i < N ; i++) {
        printf("%2d",a[i]) ;
    }
    printf("\n") ;
    return 0;
}


