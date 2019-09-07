#include "struct.h"


struct NextPageNode nullNode;
/*
���ܼ�����Ϊĳһ��ҳ���½�һ����ҳ��
�βΣ�CON����������
	  function����ҳ���Ӧ�ĺ���
	  NEXT����һ������ڵ�
*/
NextPageNode newNextPage(bool CON, Page *page,NextPageNode *NEXT) {
	struct  NextPageNode myNode;
	myNode.condition = CON;
	myNode.next = NEXT;
	myNode.page= page;
	return myNode;
}
/*
���ܼ�������һ����ҳ�������в������һ��
�βΣ�HEAD:����ͷ�ڵ�
����ֵ�����һ���ڵ�
*/
NextPageNode findLast(NextPageNode* HEAD) {
	if (HEAD->next != nullptr) findLast(HEAD->next); //�����û�����һ�����ͼ����ƽ�
	return *(HEAD);  //������󣬸����һ�����һ���ڵ�
}
/*
���ܼ������ҵ��ض�page�Ľڵ�
�βΣ�HEAD������ͷ�ڵ�
	  page��Ҫ�ҵ�ҳ��ĵ�ַ
����ֵ���ҵ��ˣ��ҵ��ĵ�ַ
	    û�ҵ�����
*/
NextPageNode findPageInNode(NextPageNode *HEAD,Page* page) {
	if (HEAD->next == nullptr) return nullNode;//����ҵ����û�ҵ�
	if (HEAD->next->page != page) findPageInNode(HEAD->next, page);  //����¸���page�������ҵģ��������
	return *(HEAD->next);
}
/*
���ܼ�����������������һ���ڵ�
�βΣ�HEAD�������ͷ�ڵ�
	  head��Ҫ�ӵĽڵ�
����ֵ����
*/
void addNode(NextPageNode* HEAD, NextPageNode* next) { //��ͷ�ڵ�ΪHEAD�����������һ��next
	if (HEAD->next != nullptr) addNode(HEAD->next, next); //�����û�����һ�����ͼ����ƽ�
	HEAD->next = next;  //������󣬸����һ�����һ���ڵ�
}
/*
���ܼ�����ɾ��һ��ҳ��Ϊpage�Ľڵ�
�βΣ�HEAD:����ͷ�ļ�
	  page��Ҫ��ѯ��ҳ��
����ֵ��false��û�ҵ���ɾ��ʧ��
		true���ҵ���ɾ���ɹ�
*/
bool detectNode(NextPageNode* HEAD,Page *page) {
	if (HEAD->next == nullptr) return false;//����ҵ����û�ҵ�
	if (HEAD->next->page != page) detectNode(HEAD->next, page);  //����¸���page�������ҵģ��������
	if (HEAD->next->next == nullptr) { HEAD->next = nullptr; return true; } //��ʱHEAD����Ҫ�ҵĽڵ�����һ���ڵ㣬�����û�����¸���˵��Ҫ�ҵĽڵ�Ϊ���һ��
	else HEAD->next = HEAD->next->next; return true;//��Ҫɾ���Ľڵ����һ����ֵ��������һ������һ��
}





/*
���ܼ������½�һ��ҳ��
�βΣ�function����ҳ���Ӧ�ĺ�����ַ
	  HEAD����ҳ��ͷ�ڵ�
����ֵ��һ���µ�ҳ��
*/

Page newPage(void(function)(void),NextPageNode *HEAD) {
	struct Page myPage;
	myPage.function= function;
	myPage.head = HEAD;
	return myPage;
}



/*
���ܼ���������һ��ҳ�����ҳ������ִ�з���������ҳ��ĺ���
�βΣ� HEAD:��ҳ�������ͷ�ڵ�
����ֵ������֮����һ��ҳ�棬���û���л������صĻ��Ǳ�ҳ��
		������л������ص�����һ��ҳ��
*/

Page switchPage(Page *page,NextPageNode *HEAD) {
	if (HEAD == nullptr) return *page; //�����ͷ�ˣ����˳�������ԭ����ҳ��
	else if (HEAD->condition == false) switchPage(page,HEAD->next);//���û���������������ת���������������һ��

	HEAD->page->function();//����ҵ��ˣ�ִ�к���
	return *(HEAD->page);//�����¸�ҳ���page
}

