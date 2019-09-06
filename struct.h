#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <malloc.h>
#include <string.h>


struct NextPageNode {
	bool condition;//跳转的条件是否成立，当它为true的时候，这个节点就会跳转
	int id; //此页的id
	struct NextPageNode* next;  //下一个节点的地址
};

struct Page {
	int id;   //这个节点的id
	struct NextPageNode* head;//这个页面的子页面的链表集合
};



struct PageList { //页面节点，没有切换的逻辑关系
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

#endif


