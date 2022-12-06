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
SNode* Search(const int const _key);
void PrintAll();
void DestroyAll();

int StrLen(const char* const _pStr);
void StrCpy(char* const _pDst, const int const _size, const char* const _pSrc);

int main()
{

	return 0;
}
void Add(const int const _key, const char* const _pMsg)
{
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	pNewNode->key = _key;
	int len = StrLen(_pMsg);
	pNewNode->msg = _pMsg;
	pNewNode->msg = (char*)malloc(sizeof(char) * (len + 1));
	StrCpy(pNewNode->msg, len, _pMsg);
	pNewNode->pNext = NULL;
	if (pHead == NULL)
	{
		pHead = pNewNode;
		return;
	}
	SNode* pCurNode = pHead;
	while (1)
	{
		if (pCurNode->key == pNewNode->key)
		{
			SAFE_FREE(pNewNode->msg);
			SAFE_FREE(pNewNode);
			return;
		}
		if (pCurNode->pNext == NULL)
		{
			pCurNode->pNext = pNewNode;
			break;
		}
		pCurNode = pCurNode->pNext;
	}

}

SNode* Search(const int const _key)
{
	if (pHead == NULL) return NULL;
	SNode* pCurNode = pHead;
	while (pCurNode != NULL)
	{
		if (pCurNode->key == _key)
			return pCurNode;
		pCurNode = pCurNode->pNext;
	}
	return NULL;
}

void PrintAll()
{
	if (pHead == NULL)
	{
		printf("Is Empty! \n");
		return;
	}
	SNode* pCurNode = pHead;
	int cnt = 0;
	while (pCurNode != NULL)
	{
		printf("{%d : %s} - ", pCurNode->key, pCurNode->msg);
		pCurNode = pCurNode->pNext;
		++cnt;
	}
	printf("(%d)\n", cnt);
}

void DestroyAll()
{
	if (pHead == NULL) return;
	SNode* pCurNode = pHead;
	SNode* pDestroyNode = NULL;
	while (pCurNode != NULL)
	{
		pDestroyNode = pCurNode;
		pCurNode = pCurNode->pNext;

	}
}

int StrLen(const char* const _pStr)
{
	if (_pStr == NULL) return -1;
	int cnt = 0;
	while (_pStr[cnt] != '\0')
	{
		++cnt;
	}
	return cnt;
}

void StrCpy(char* const _pDst, const int const _size, const char* const _pSrc)
{
	if (_pDst == NULL || _pSrc == NULL) return;
	for (int i = 0; i < _size; ++i)
	{
		_pDst[i] = _pSrc[i];
	}
	_pDst[_size] = '\0';
}
