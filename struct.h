#ifndef __STRUCT_H_
#define __STRUCT_H_

NextPageNode newNextPage(bool CON, int ID, NextPageNode* NEXT);
NextPageNode addNode(NextPageNode* HEAD, NextPageNode* next);
NextPageNode detectNode(NextPageNode* HEAD, int id);
Page newPage(char NAME[], int ID, NextPageNode* HEAD);

#endif


