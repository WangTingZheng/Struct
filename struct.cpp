#include "struct.h"
#include <malloc.h>
#include <string.h>
#define nullID -1
#define maxPageName 10


typedef struct NextPageNode {
	bool condition;//跳转的条件是否成立，当它为true的时候，这个节点就会跳转
	int id; //此页的id
	struct NextPageNode *next;  //下一个节点的地址
};

typedef struct Page {
	char name[maxPageName];//这个页面的名字
	int id;   //这个节点的id
	struct NextPageNode *head;//这个页面的子页面的链表集合
};



NextPageNode newNextPage(bool CON,int ID,NextPageNode *NEXT) {
	NextPageNode myNode;
	myNode.condition = CON;
	myNode.next = NEXT;
	myNode.id = ID;
	return myNode;
}
NextPageNode addNode(NextPageNode* HEAD, NextPageNode* next) { //在头节点为HEAD的链表里添加一个next

}
NextPageNode detectNode(NextPageNode* HEAD, int id) {//在头节点为HEAD的链表里删除一个固定id的节点

}
Page newPage(char NAME[], int ID,NextPageNode *HEAD) {
	struct Page myPage;
	strcpy(myPage.name, NAME);
	myPage.id = ID;
	myPage.head = HEAD;
}




void active() {

}
void disPlay(int id) {

}