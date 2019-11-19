#include <stdio.h>

int main(void) {

	int x = 0x21;
	char test;

	int* pint = &x;
	test = *((char *)pint);

	if (test == 0x0) {
		printf("Current Endian-ness: Big boi\n");
	} else {
		printf("Current Endian-ness: Little bitch\n");
	}

	return 0;
}