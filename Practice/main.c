#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define SAFE_FREE(p)\
{\
do{if(p){free(p); p=NULL;}}while(0);\
}
typedef struct _SNode
{
	int key;
	char* msg;
	struct _SNode* pNext;
}SNode;

SNode* pHead = NULL;
void Add(const int const _key, const char* const _pMsg);
SNode* S