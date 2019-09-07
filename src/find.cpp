#include "find.h"
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
	pageList.function = nullptr;
	pageList.nextPageList = nullptr;
	pageList.page = nullptr;
}

/*
���ܼ������ж�id�Ƿ��ظ�
�βΣ�pagelist�������ͷ�ڵ�ĵ�ַ
	  id��Ҫ������id
����ֵ���ظ���true�����ظ���false
*/

bool findIdSame(PageList* pagelist, void(function)(void)) {
	if (*((*pagelist).function) != *function && (*pagelist).nextPageList != nullptr) findIdSame((*pagelist).nextPageList, function);
	else if (*((*pagelist).function) == *function) return true;
	else return false;
}


void newPageList(void(function)(void), Page* page, PageList* next) {//���������������һ���ڵ�
	PageList myPageListLast = findLastPageList(&pageList);
	myPageListLast.function = function;
	myPageListLast.nextPageList = nullptr;
	myPageListLast.page = page;
}


void detectPageList(void(function)(void)) { //ɾ���̶�id�Ľڵ�
	PageList myPageListFont = findPageListFont(&pageList, function);//�ҵ�idǰ��һ���ڵ�
	PageList myPageList = findPageList(&pageList, function);//�ҵ�id��Ӧ�Ľڵ�
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
PageList findPageListFont(PageList* pagelist, void(function)(void)) {   //�ҵ��̶�id�Ľڵ�
	if ((*(*pagelist).nextPageList).function != function) findPageList((*pagelist).nextPageList, function);
	return *pagelist;
}

/*
���ܼ���������id�����βεĽڵ�
�βΣ�pagelist����һ���ڵ�ĵ�ַ
	  id����Ҫ���ҵ�id
����ֵ��pagelist���ҵ��Ľڵ㣨���������ǵ�ַ��
*/

PageList findPageList(PageList* pagelist, void(function)(void)) {//�ҵ��̶�id�Ľڵ�
	return (*findPageListFont(pagelist, function).nextPageList);
}
/*
���ܼ������ҵ���������һ���ڵ�
�βΣ�pagelist����һ���ڵ�ĵ�ַ��һ���ͷ�ڵ㿪ʼ
����ֵ�����һ���ڵ㱾��
*/
PageList findLastPageList(PageList* pagelist) {//�ҵ���������һ���ڵ�
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