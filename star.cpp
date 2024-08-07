#include <stdio.h>

<<<<<<< HEAD
void ComplexFunc(double num1, double num2){
        printf("%f + %f = %f ", num1, num2, num1+num2);
}

int main(int argc, char * argv[]){
    
    printf("Argc : %d\n", argc);
    printf("Argv[0] : %s\n", argv[0]);
    printf("Argv[1] : %s\n", argv[1]);
=======
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
>>>>>>> fa88b5a5a8f5a3731a578976f113142c7c791af9

    return 0;
}