#include "struct.h"
#include <malloc.h>
#include <string.h>
#define nullID -1
#define maxPageName 10


typedef struct NextPageNode {
	bool condition;//��ת�������Ƿ����������Ϊtrue��ʱ������ڵ�ͻ���ת
	int id; //��ҳ��id
	struct NextPageNode *next;  //��һ���ڵ�ĵ�ַ
};

typedef struct Page {
	char name[maxPageName];//���ҳ�������
	int id;   //����ڵ��id
	struct NextPageNode *head;//���ҳ�����ҳ���������
};



NextPageNode newNextPage(bool CON,int ID,NextPageNode *NEXT) {
	NextPageNode myNode;
	myNode.condition = CON;
	myNode.next = NEXT;
	myNode.id = ID;
	return myNode;
}
NextPageNode addNode(NextPageNode* HEAD, NextPageNode* next) { //��ͷ�ڵ�ΪHEAD�����������һ��next

}
NextPageNode detectNode(NextPageNode* HEAD, int id) {//��ͷ�ڵ�ΪHEAD��������ɾ��һ���̶�id�Ľڵ�

}
Page newPage(char NAME[], int ID,NextPageNode *HEAD) {
	struct Page myPage;
	strcpy(myPage.name, NAME);
	myPage.id = ID;
	myPage.head = HEAD;
}




void active() {

}
void disPlay(int id) {

}