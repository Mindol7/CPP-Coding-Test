#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 16
#define OVERSIZE 8

int main(){
     
    unsigned long address_diff;
    char * buf1 = (char *)malloc(BUFSIZE), *buf2 = (char *)malloc(BUFSIZE);

    address_diff = (unsigned long)buf2 - (unsigned long)buf1;
    printf("buf1 = %p, buf2 = %p, address_diff = 0x%x bytes\n", buf1, buf2, address_diff);

    memset(buf2, 'A', BUFSIZE-1), buf2[BUFSIZE-1] = '\0';
    printf("Before bufferoverflow buf1 = %s \n", buf1);
    printf("Before bufferoverflow buf2 = %s \n\n", buf2);

    memset(buf1, 'B', (unsigned int)(address_diff) + OVERSIZE);
    printf("After bufferoverflow buf1 = %s \n", buf1);
    printf("After bufferoverflow buf2 = %s \n\n", buf2);

    return 0;
}