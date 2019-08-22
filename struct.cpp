#include "struct.h"
#include <malloc.h>

#define maxNextPage 10

page* NowPage = (page*)malloc(sizeof(page));

struct nextpage{           //һ����ҳ�棬����һ��ҳ���ַ��һ���жϺ���
	page* mypage;
	bool (*conFun)(void);
};
struct NextPage{               //һ��ҳ�����ҳ�漯
	nextpage* NP[maxNextPage];
};
struct page {                   //һ��ҳ�档������ҳ��ͻ滭������ҳ��id
	NextPage* mynextpage;
	void (*drawFun)(void);
	int id;
};

/*
���ܣ��½�һ����ҳ��
���룺
	myp:��ҳ���ҳ���ַ��
	myconFun����ҳ����ת������
���أ������õ���ҳ��
*/
nextpage* newnextpage(page* myp,bool (*myconFun)(void)) {   
	nextpage* mynextpage;
	mynextpage = (nextpage*)malloc(sizeof(nextpage));
	mynextpage->mypage = myp;
	mynextpage->conFun = myconFun;

	return mynextpage;
}
/*
���ܣ��½�һ���µ���ҳ�漯�����ҳ�ʼ��Ϊ��
���룺��
���أ��½��õ���ҳ�漯
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
���ܣ�����ҳ�漯�����һ����ҳ��
���룺
	myNP��Ҫ��ӵ���ҳ�漯
	mynextpage��Ҫ��ӵ���ҳ��
	id��Ҫ�����ҳ������ҳ�漯�е�id�ţ�0����maxNextPage
���أ�������֮�����ҳ�漯
*/

NextPage* addNextPage(NextPage* myNP, nextpage* mynextpage,int id) {
	myNP->NP[id] = mynextpage;
	return myNP;
}

/*
���ܣ��½�һ��ҳ��
���룺
	myNP��ҳ�����ҳ�漯
	mydrawFun����ҳ��Ļ滭����
	myid����ҳ���id
���أ����ش�����֮���ҳ��
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
���ܣ��л�ҳ��
���룺
	mypage:��ǰ��ҳ��
���أ���
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
���ܣ������棬����һҳ�Ļ���
���룺��
���أ���
*/
void draw() {
	jumpNextPage(NowPage);
	NowPage->drawFun();
}