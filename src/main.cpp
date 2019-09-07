#include "struct.h"
#include "page.h"
int main() {
	
	Page mainPage=newPage(page_1_1, &(newNextPage(false, &newPage(page_1_2, nullptr), nullptr)));
	mainPage.function();
	mainPage.head->condition = true;
	switchPage(&mainPage, mainPage.head);
}