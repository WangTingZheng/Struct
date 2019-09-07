#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <malloc.h>
#include <string.h>

/*
	子页面链表的子节点
	condition：跳转条件
	id：子页面id
	next：下一个子节点
*/
struct NextPageNode {
	bool condition;//跳转的条件是否成立，当它为true的时候，这个节点就会跳转
	int id; //此页的id
	struct NextPageNode* next;  //下一个节点的地址
};

/*
	页面
	id：页面id
	head：子页面链表，这里储存的是链表的表头
*/
struct Page {
	int id;   //这个节点的id
	//void(*function)(void); //页面对应的函数
	struct NextPageNode* head;//这个页面的子页面的链表集合
};


/*
	页面储存节点，没有切换的逻辑关系
	id：子页面的id
	page：当前子页面的页面指针
	nextPageList：下一个子页面
*/
struct PageList { 
	int id;
	struct Page* page;
	struct PageList* nextPageList;
};



void initPageList(); 
void newPageList(int id, Page* page, PageList* next);
void detectPageList(int id);
PageList findPageListFont(PageList* pagelist, int id);
PageList findPageList(PageList* pagelist, int id);
PageList findLastPageList(PageList* pagelist);
PageList returnHead();
bool findIdSame(PageList* pagelist, int id);

#endif


