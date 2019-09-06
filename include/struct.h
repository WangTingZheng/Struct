#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <malloc.h>
#include <string.h>


struct NextPageNode {
	bool condition;//��ת�������Ƿ����������Ϊtrue��ʱ������ڵ�ͻ���ת
	int id; //��ҳ��id
	struct NextPageNode* next;  //��һ���ڵ�ĵ�ַ
};

struct Page {
	int id;   //����ڵ��id
	struct NextPageNode* head;//���ҳ�����ҳ���������
};



struct PageList { //ҳ��ڵ㣬û���л����߼���ϵ
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


