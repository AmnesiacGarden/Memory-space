#include <stdio.h>

void h_sorting(int a[], int n, int h) {
    int i, j, x;
    
    for(i = h ; i < n ; i++) {
        x = a[i] ;
        for(j = i - h ; j >= 0 && a[j] > x ; j = j - h) {
            a[j+h] = a[j] ;
        }
        a[j+h] = x ;
    } 
}

void shell_sort(int a[], int n) {
    int i;
    int h[4] ={8,4,2,1};

    for(i = 0 ; i < 4 ; i++) {
        h_sorting(a, n, h[i]);
    }
}

#define N 10

int main() {
    int a[N] , i;
    for(i = 0 ; i < N ; i++) {
        scanf("%d",&a[i]) ;
    }

    shell_sort(a, N);

    for(i = 0 ; i < N ; i++) {
        printf("%2d",a[i]) ;
    }
    printf("\n") ;
    return 0;
}


