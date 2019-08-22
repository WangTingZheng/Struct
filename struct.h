#ifndef __STRUCT_H_
#define __STRUCT_H_

nextpage* newnextpage(page* myp, bool (*myconFun)(void));
NextPage* newNextPage();
NextPage* addNextPage(NextPage* myNP, nextpage* mynextpage, int id);
page* newPage(NextPage* myNP, void (*mydrawFun)(void), int myid);
void jumpNextPage(page* mypage);
void draw(void);

#endif


