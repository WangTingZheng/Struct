#include "struct.h"
#define nullID -1
struct PageList pageList;

/*
功能简述：初始化页面链表，也就是初始化头节点
功能详述：初始化头节点的id为nullID,
		  下一个节点的地址为空
		  当前页面为空
形参：无
返回值：无
*/
void initPageList() {
	pageList.id = nullID;
	pageList.nextPageList = nullptr;
	pageList.page = nullptr;
}
/*
功能简述：判断id是否重复
形参：pagelist：链表的头节点的地址
	  id：要搜索的id
返回值：重复：true，不重复：false
*/

bool findIdSame(PageList *pagelist,int id) {
	if ((*pagelist).id != id && (*pagelist).nextPageList != nullptr) findIdSame((*pagelist).nextPageList, id);
	else if ((*pagelist).id == id) return true;
	else return false;
}


void newPageList(int id,Page* page,PageList *next) {//在链表最后新增加一个节点
	PageList myPageListLast = findLastPageList(&pageList);
	myPageListLast.id = id;
	myPageListLast.nextPageList = nullptr;
	myPageListLast.page = page;
}


void detectPageList(int id) { //删除固定id的节点
	PageList myPageListFont=findPageListFont(&pageList,id);//找到id前的一个节点
	PageList myPageList = findPageList(&pageList,id);//找到id对应的节点
	if (myPageList.nextPageList != nullptr)
		myPageListFont.nextPageList = myPageList.nextPageList;//把id前的节点的next跨过id,连接到后一个
	else myPageListFont.nextPageList = nullptr;
}

/*
功能简述：返回id等于形参的节点的前一个节点
形参：pagelist：上一个节点的地址
	  id：所要查找的id
返回值：pagelist：找到的节点（它本身，不是地址）
*/
PageList findPageListFont(PageList* pagelist, int id) {   //找到固定id的节点
	if ((*(*pagelist).nextPageList).id != id) findPageList((*pagelist).nextPageList, id);
	return *pagelist;
}

/*
功能简述：返回id等于形参的节点
形参：pagelist：上一个节点的地址
	  id：所要查找的id
返回值：pagelist：找到的节点（它本身，不是地址）
*/

PageList findPageList(PageList *pagelist,int id) {//找到固定id的节点
	return (*findPageListFont(pagelist,id).nextPageList);
}
/*
功能简述：找到链表的最后一个节点
形参：pagelist：上一个节点的地址，一般从头节点开始
返回值：最后一个节点本身
*/
PageList findLastPageList(PageList *pagelist) {//找到链表的最后一个节点
	if ((*pagelist).nextPageList != nullptr) findLastPageList((*pagelist).nextPageList);
	return *pagelist;
}
/*
功能简述：返回链表的头节点本身
形参：无
返回值：头节点本身
*/
PageList returnHead() {
	return pageList;
}



/*
功能简述：为某一个页面新建一组子页面
形参：CON：
*/
NextPageNode newNextPage(bool CON,int ID,NextPageNode *NEXT) {
	struct  NextPageNode myNode;
	myNode.condition = CON;
	myNode.next = NEXT;
	myNode.id = ID;
	return myNode;
}
NextPageNode addNode(NextPageNode* HEAD, NextPageNode* next) { //在头节点为HEAD的链表里添加一个next

	return *HEAD;
}
NextPageNode detectNode(NextPageNode* HEAD, int id) {//在头节点为HEAD的链表里删除一个固定id的节点
	return *HEAD;
}

Page newPage(int ID,NextPageNode *HEAD) {
	struct Page myPage;
	myPage.id = ID;
	myPage.head = HEAD;
	return myPage;
}

/*
Page findPage(int id) {

}
*/

void importOrder(int fontID,int afterID) {

}