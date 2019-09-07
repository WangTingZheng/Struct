#include "struct.h"
#define nullID -1
struct PageList pageList;

/*
���ܼ�������ʼ��ҳ������Ҳ���ǳ�ʼ��ͷ�ڵ�
������������ʼ��ͷ�ڵ��idΪnullID,
		  ��һ���ڵ�ĵ�ַΪ��
		  ��ǰҳ��Ϊ��
�βΣ���
����ֵ����
*/
void initPageList() {
	pageList.id = nullID;
	pageList.nextPageList = nullptr;
	pageList.page = nullptr;
}
/*
���ܼ������ж�id�Ƿ��ظ�
�βΣ�pagelist�������ͷ�ڵ�ĵ�ַ
	  id��Ҫ������id
����ֵ���ظ���true�����ظ���false
*/

bool findIdSame(PageList *pagelist,int id) {
	if ((*pagelist).id != id && (*pagelist).nextPageList != nullptr) findIdSame((*pagelist).nextPageList, id);
	else if ((*pagelist).id == id) return true;
	else return false;
}


void newPageList(int id,Page* page,PageList *next) {//���������������һ���ڵ�
	PageList myPageListLast = findLastPageList(&pageList);
	myPageListLast.id = id;
	myPageListLast.nextPageList = nullptr;
	myPageListLast.page = page;
}


void detectPageList(int id) { //ɾ���̶�id�Ľڵ�
	PageList myPageListFont=findPageListFont(&pageList,id);//�ҵ�idǰ��һ���ڵ�
	PageList myPageList = findPageList(&pageList,id);//�ҵ�id��Ӧ�Ľڵ�
	if (myPageList.nextPageList != nullptr)
		myPageListFont.nextPageList = myPageList.nextPageList;//��idǰ�Ľڵ��next���id,���ӵ���һ��
	else myPageListFont.nextPageList = nullptr;
}

/*
���ܼ���������id�����βεĽڵ��ǰһ���ڵ�
�βΣ�pagelist����һ���ڵ�ĵ�ַ
	  id����Ҫ���ҵ�id
����ֵ��pagelist���ҵ��Ľڵ㣨���������ǵ�ַ��
*/
PageList findPageListFont(PageList* pagelist, int id) {   //�ҵ��̶�id�Ľڵ�
	if ((*(*pagelist).nextPageList).id != id) findPageList((*pagelist).nextPageList, id);
	return *pagelist;
}

/*
���ܼ���������id�����βεĽڵ�
�βΣ�pagelist����һ���ڵ�ĵ�ַ
	  id����Ҫ���ҵ�id
����ֵ��pagelist���ҵ��Ľڵ㣨���������ǵ�ַ��
*/

PageList findPageList(PageList *pagelist,int id) {//�ҵ��̶�id�Ľڵ�
	return (*findPageListFont(pagelist,id).nextPageList);
}
/*
���ܼ������ҵ���������һ���ڵ�
�βΣ�pagelist����һ���ڵ�ĵ�ַ��һ���ͷ�ڵ㿪ʼ
����ֵ�����һ���ڵ㱾��
*/
PageList findLastPageList(PageList *pagelist) {//�ҵ���������һ���ڵ�
	if ((*pagelist).nextPageList != nullptr) findLastPageList((*pagelist).nextPageList);
	return *pagelist;
}
/*
���ܼ��������������ͷ�ڵ㱾��
�βΣ���
����ֵ��ͷ�ڵ㱾��
*/
PageList returnHead() {
	return pageList;
}



/*
���ܼ�����Ϊĳһ��ҳ���½�һ����ҳ��
�βΣ�CON��
*/
NextPageNode newNextPage(bool CON,int ID,NextPageNode *NEXT) {
	struct  NextPageNode myNode;
	myNode.condition = CON;
	myNode.next = NEXT;
	myNode.id = ID;
	return myNode;
}
NextPageNode addNode(NextPageNode* HEAD, NextPageNode* next) { //��ͷ�ڵ�ΪHEAD�����������һ��next

	return *HEAD;
}
NextPageNode detectNode(NextPageNode* HEAD, int id) {//��ͷ�ڵ�ΪHEAD��������ɾ��һ���̶�id�Ľڵ�
	return *HEAD;
}

Page newPage(int ID,NextPageNode *HEAD) {
	struct Page myPage;
	myPage.id = ID;
	myPage.head = HEAD;
	return myPage;
}

/*
Page findPage(int id) {

}
*/

void importOrder(int fontID,int afterID) {

}