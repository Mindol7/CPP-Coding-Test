#include <stdio.h>

void swap(int * p1, int * p2){
    int temp;

    temp = *p1;
    *p2 = *p1;
    *p1 = temp;
}

int main(){
    int a = 10;
    int b = 20;
    
    printf("Before: %d, %d\n", a, b);
    swap(&a, &b);
    printf("After : %d, %d\n", a, b);

    return 0;
}