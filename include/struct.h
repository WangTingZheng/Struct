#ifndef __STRUCT_H_
#define __STRUCT_H_

/*
	子页面链表的子节点
	condition：跳转条件
	id：子页面id
	next：下一个子节点
*/
struct NextPageNode {
	bool condition;//跳转的条件是否成立，当它为true的时候，这个节点就会跳转
	struct Page* page;
	struct NextPageNode* next;  //下一个节点的地址
};

/*
	页面
	function:页面实现函数指针
	head：子页面链表，这里储存的是链表的表头
*/
struct Page {
	void(*function)(void); //页面对应的函数
	struct NextPageNode* head;//这个页面的子页面的链表集合
};


/*
	页面储存节点，没有切换的逻辑关系
	id：子页面的id
	page：当前子页面的页面指针
	nextPageList：下一个子页面
*/

NextPageNode newNextPage(bool CON, Page* page, NextPageNode* NEXT);
void addNode(NextPageNode* HEAD, NextPageNode* next);
bool detectNode(NextPageNode* HEAD, Page* page);
NextPageNode findLast(NextPageNode* HEAD);
NextPageNode findPageInNode(NextPageNode* HEAD, Page* page);


Page newPage(void(function)(void), NextPageNode* HEAD);

Page switchPage(Page* page, NextPageNode* HEAD);

#endif


