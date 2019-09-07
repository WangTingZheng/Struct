#ifndef __STRUCT_H_
#define __STRUCT_H_

#include <malloc.h>
#include <string.h>

/*
	��ҳ��������ӽڵ�
	condition����ת����
	id����ҳ��id
	next����һ���ӽڵ�
*/
struct NextPageNode {
	bool condition;//��ת�������Ƿ����������Ϊtrue��ʱ������ڵ�ͻ���ת
	int id; //��ҳ��id
	struct NextPageNode* next;  //��һ���ڵ�ĵ�ַ
};

/*
	ҳ��
	id��ҳ��id
	head����ҳ���������ﴢ���������ı�ͷ
*/
struct Page {
	int id;   //����ڵ��id
	//void(*function)(void); //ҳ���Ӧ�ĺ���
	struct NextPageNode* head;//���ҳ�����ҳ���������
};


/*
	ҳ�洢��ڵ㣬û���л����߼���ϵ
	id����ҳ���id
	page����ǰ��ҳ���ҳ��ָ��
	nextPageList����һ����ҳ��
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


