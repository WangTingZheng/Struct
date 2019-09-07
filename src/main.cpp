#include "struct.h"
#include <stdio.h>

int main() {
	initPageList();
	printf("%d", findIdSame(&returnHead(),1));
	return 0;
}