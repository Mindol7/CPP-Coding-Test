#include <stdio.h>

int main(){
    int * arr[5];
    int x = 1;
    for(int i = 0; i<5; ++i){
        for(int j = 0; j<5; ++j){
            arr[i][j] = x;
            x++;
        }
    }

    int ** pptr = arr;

    for(int i = 0; i<5; ++i){
        for(int j = 0; j<5; ++j){
            printf("VALUE : %d", pptr[i][j]);
        }
        printf("\n");
    }

    return 0;
}