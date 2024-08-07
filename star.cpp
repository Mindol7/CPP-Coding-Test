#include <stdio.h>

void ComplexFunc(double num1, double num2){
        printf("%f + %f = %f ", num1, num2, num1+num2);
}

int main(int argc, char * argv[]){
    
    printf("Argc : %d\n", argc);
    printf("Argv[0] : %s\n", argv[0]);
    printf("Argv[1] : %s\n", argv[1]);

    return 0;
}