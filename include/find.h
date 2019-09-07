#ifndef __FIND_H
#define __FIND_H

struct PageList {
	void(*function)(void); //页面对应的函数
	struct Page* page;
	struct PageList* nextPageList;
};

void initPageList();
void newPageList(void(function)(void), Page* page, PageList* next);
void detectPageList(void(function)(void));
PageList findPageListFont(PageList* pagelist, void(function)(void));
PageList findPageList(PageList* pagelist, void(function)(void));
PageList findLastPageList(PageList* pagelist);
PageList returnHead();
bool findIdSame(PageList* pagelist, void(function)(void));

#endif 
