#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    u_long address_diff;
    char * buf1 = (char*)malloc(16);
    char * buf2 = (char*)malloc(16);

    address_diff = (u_long)buf2 - (u_long)buf1;
    memset(buf2, 'A', 15), buf2[15] = '\0';
    memset(buf1, 'B', (u_int)(address_diff+8));

    printf("After bufferoverflow buf2 = %s\n", buf2);

    return 0;
}