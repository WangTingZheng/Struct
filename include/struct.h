#ifndef __STRUCT_H_
#define __STRUCT_H_

/*
	��ҳ��������ӽڵ�
	condition����ת����
	id����ҳ��id
	next����һ���ӽڵ�
*/
struct NextPageNode {
	bool condition;//��ת�������Ƿ����������Ϊtrue��ʱ������ڵ�ͻ���ת
	struct Page* page;
	struct NextPageNode* next;  //��һ���ڵ�ĵ�ַ
};

/*
	ҳ��
	function:ҳ��ʵ�ֺ���ָ��
	head����ҳ���������ﴢ���������ı�ͷ
*/
struct Page {
	void(*function)(void); //ҳ���Ӧ�ĺ���
	struct NextPageNode* head;//���ҳ�����ҳ���������
};


/*
	ҳ�洢��ڵ㣬û���л����߼���ϵ
	id����ҳ���id
	page����ǰ��ҳ���ҳ��ָ��
	nextPageList����һ����ҳ��
*/

NextPageNode newNextPage(bool CON, Page* page, NextPageNode* NEXT);
void addNode(NextPageNode* HEAD, NextPageNode* next);
bool detectNode(NextPageNode* HEAD, Page* page);
NextPageNode findLast(NextPageNode* HEAD);
NextPageNode findPageInNode(NextPageNode* HEAD, Page* page);


Page newPage(void(function)(void), NextPageNode* HEAD);

Page switchPage(Page* page, NextPageNode* HEAD);

#endif


