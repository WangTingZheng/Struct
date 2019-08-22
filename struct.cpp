#include "struct.h"
#include <malloc.h>

#define maxNextPage 10

page* NowPage = (page*)malloc(sizeof(page));

struct nextpage{           //一个子页面，包括一个页面地址和一个判断函数
	page* mypage;
	bool (*conFun)(void);
};
struct NextPage{               //一个页面的子页面集
	nextpage* NP[maxNextPage];
};
struct page {                   //一个页面。包括子页面和绘画函数和页面id
	NextPage* mynextpage;
	void (*drawFun)(void);
	int id;
};

/*
功能：新建一个子页面
输入：
	myp:子页面的页面地址；
	myconFun：子页面跳转的条件
返回：建立好的子页面
*/
nextpage* newnextpage(page* myp,bool (*myconFun)(void)) {   
	nextpage* mynextpage;
	mynextpage = (nextpage*)malloc(sizeof(nextpage));
	mynextpage->mypage = myp;
	mynextpage->conFun = myconFun;

	return mynextpage;
}
/*
功能：新建一个新的子页面集，并且初始化为空
输入：无
返回：新建好的子页面集
*/
NextPage* newNextPage() {
    NextPage* myNP;
	myNP=(NextPage*)malloc(sizeof(NextPage));
	for (int i = 0; i < maxNextPage; i++) {
		myNP->NP[i] = nullptr;
	}
	return myNP;
}
/*
功能：在子页面集中添加一个子页面
输入：
	myNP：要添加的子页面集
	mynextpage：要添加的子页面
	id：要添加子页面在子页面集中的id号，0——maxNextPage
返回：添加完成之后的子页面集
*/

NextPage* addNextPage(NextPage* myNP, nextpage* mynextpage,int id) {
	myNP->NP[id] = mynextpage;
	return myNP;
}

/*
功能：新建一个页面
输入：
	myNP：页面的子页面集
	mydrawFun：此页面的绘画函数
	myid：此页面的id
返回：返回创立好之后的页面
*/

page* newPage(NextPage *myNP,void (*mydrawFun)(void),int myid) {
	page* myP;
	myP = (page*)malloc(sizeof(page));
	myP->id = myid;
	myP->drawFun = mydrawFun;
	myP->mynextpage = myNP;
	return myP;
}

/*
功能：切换页面
输入：
	mypage:当前的页面
返回：无
*/
void jumpNextPage(page* mypage) {
	for (int i = 0; i < maxNextPage; i++) {
		if (mypage->mynextpage->NP[i]->conFun() == true) {
			NowPage = mypage->mynextpage->NP[i];
			break;
		}
	}
}

/*
功能：画画面，画下一页的画面
输入：无
返回：无
*/
void draw() {
	jumpNextPage(NowPage);
	NowPage->drawFun();
}