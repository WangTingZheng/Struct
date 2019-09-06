#include "struct.h"
#include <stdio.h>

int main() {
	initPageList();
	printf("%d", findLastPageList(&(returnHead())).id);
	return 0;
}