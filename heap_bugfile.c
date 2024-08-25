#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

#define ERROR -1

int fucntion(const char *str){
	printf("Normal function called by function pointer\n", str);
	return 0;
}

int main(int argc, char **argv){
	static char buf[16];
	static int (*funcptr)(const char *str);

	if (argc <= 2) {
		fprintf(stderr, "Usage: %s <buffer> <fucntion's arg>\n", argv[0]);
		exit(ERROR);
	}
	printf("Address of system() = %p\n", &system);

	funcptr = (int (*)(const char *str))fucntion;
	memset(buf, 0, sizeof(buf));
	strncpy(buf, argv[1], strlen(argv[1]));
	(void)(*funcptr)(argv[2]);
	return 0;
}
