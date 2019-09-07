#include "find.h"
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
	pageList.function = nullptr;
	pageList.nextPageList = nullptr;
	pageList.page = nullptr;
}

/*
功能简述：判断id是否重复
形参：pagelist：链表的头节点的地址
	  id：要搜索的id
返回值：重复：true，不重复：false
*/

bool findIdSame(PageList* pagelist, void(function)(void)) {
	if (*((*pagelist).function) != *function && (*pagelist).nextPageList != nullptr) findIdSame((*pagelist).nextPageList, function);
	else if (*((*pagelist).function) == *function) return true;
	else return false;
}


void newPageList(void(function)(void), Page* page, PageList* next) {//在链表最后新增加一个节点
	PageList myPageListLast = findLastPageList(&pageList);
	myPageListLast.function = function;
	myPageListLast.nextPageList = nullptr;
	myPageListLast.page = page;
}


void detectPageList(void(function)(void)) { //删除固定id的节点
	PageList myPageListFont = findPageListFont(&pageList, function);//找到id前的一个节点
	PageList myPageList = findPageList(&pageList, function);//找到id对应的节点
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
PageList findPageListFont(PageList* pagelist, void(function)(void)) {   //找到固定id的节点
	if ((*(*pagelist).nextPageList).function != function) findPageList((*pagelist).nextPageList, function);
	return *pagelist;
}

/*
功能简述：返回id等于形参的节点
形参：pagelist：上一个节点的地址
	  id：所要查找的id
返回值：pagelist：找到的节点（它本身，不是地址）
*/

PageList findPageList(PageList* pagelist, void(function)(void)) {//找到固定id的节点
	return (*findPageListFont(pagelist, function).nextPageList);
}
/*
功能简述：找到链表的最后一个节点
形参：pagelist：上一个节点的地址，一般从头节点开始
返回值：最后一个节点本身
*/
PageList findLastPageList(PageList* pagelist) {//找到链表的最后一个节点
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