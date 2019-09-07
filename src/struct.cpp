#include "struct.h"


struct NextPageNode nullNode;
/*
功能简述：为某一个页面新建一组子页面
形参：CON：触发条件
	  function：子页面对应的函数
	  NEXT：下一个链表节点
*/
NextPageNode newNextPage(bool CON, Page *page,NextPageNode *NEXT) {
	struct  NextPageNode myNode;
	myNode.condition = CON;
	myNode.next = NEXT;
	myNode.page= page;
	return myNode;
}
/*
功能简述：在一个子页面链表中查找最后一个
形参：HEAD:链表头节点
返回值：最后一个节点
*/
NextPageNode findLast(NextPageNode* HEAD) {
	if (HEAD->next != nullptr) findLast(HEAD->next); //如果还没到最后一个，就继续推进
	return *(HEAD);  //到了最后，给最后一个添加一个节点
}
/*
功能简述：找到特定page的节点
形参：HEAD：链表头节点
	  page：要找的页面的地址
返回值：找到了：找到的地址
	    没找到：空
*/
NextPageNode findPageInNode(NextPageNode *HEAD,Page* page) {
	if (HEAD->next == nullptr) return nullNode;//如果找到最后没找到
	if (HEAD->next->page != page) findPageInNode(HEAD->next, page);  //如果下个的page不是想找的，则继续找
	return *(HEAD->next);
}
/*
功能简述：在链表最后添加一个节点
形参：HEAD：链表的头节点
	  head：要加的节点
返回值：无
*/
void addNode(NextPageNode* HEAD, NextPageNode* next) { //在头节点为HEAD的链表里添加一个next
	if (HEAD->next != nullptr) addNode(HEAD->next, next); //如果还没到最后一个，就继续推进
	HEAD->next = next;  //到了最后，给最后一个添加一个节点
}
/*
功能简述：删除一个页面为page的节点
形参：HEAD:链表头文件
	  page：要查询的页面
返回值：false：没找到，删除失败
		true：找到，删除成功
*/
bool detectNode(NextPageNode* HEAD,Page *page) {
	if (HEAD->next == nullptr) return false;//如果找到最后没找到
	if (HEAD->next->page != page) detectNode(HEAD->next, page);  //如果下个的page不是想找的，则继续找
	if (HEAD->next->next == nullptr) { HEAD->next = nullptr; return true; } //此时HEAD就是要找的节点是上一个节点，如果它没有下下个，说明要找的节点为最后一个
	else HEAD->next = HEAD->next->next; return true;//把要删除的节点的下一个赋值给它的上一个的下一个
}





/*
功能简述：新建一个页面
形参：function：此页面对应的函数地址
	  HEAD：子页面头节点
返回值：一个新的页面
*/

Page newPage(void(function)(void),NextPageNode *HEAD) {
	struct Page myPage;
	myPage.function= function;
	myPage.head = HEAD;
	return myPage;
}



/*
功能简述：遍历一个页面的子页面链表，执行符合条件的页面的函数
形参： HEAD:子页面链表的头节点
返回值：遍历之后下一个页面，如果没有切换，返回的还是本页面
		如果有切换，返回的是下一个页面
*/

Page switchPage(Page *page,NextPageNode *HEAD) {
	if (HEAD == nullptr) return *page; //如果到头了，则退出，返回原来的页面
	else if (HEAD->condition == false) switchPage(page,HEAD->next);//如果没到，如果不满足跳转条件，则继续找下一个

	HEAD->page->function();//如果找到了，执行函数
	return *(HEAD->page);//返回下个页面的page
}

