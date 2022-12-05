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
} SNode;

SNode* pHead = NULL;
void Add(const int const _key, const char* const _pMsg);
SNode* Search(const int const _key);
void PrintAll();
void DestroyAll();

// # Utility Function - 서포트 함수들.
// 문자열 길이 반환
int StrLen(const char* const _pStr);
void StrCpy(char* const  _pDst, const int const _size, const char* const _pSrc);

int main()
{
	Add(1, "qwer");
	Add(1, "tyui");
	Add(4, "asdf");
	Add(13, "zcxv");
	PrintAll();
	printf("Search(1) : %s\n",
		Search(1) != NULL ? "True" : "False");
	printf("Search(5) : %s\n",
		Search(5) != NULL ? "True" : "False");
	SNode* searchNode = Search(13);
	printf("{%d : %s}\n", searchNode->key, searchNode->msg);
	DestroyAll();
	PrintAll();
	return 0;
}
void Add(const int const _key, const char* const _pMsg)
{
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	pNewNode->key = _key;
	// Shallow Copy (얕은 복사)
	// Deep Copy (깊은 복사)
	//pNewNode->msg = _msg; // 주소값만 복사된다. Add함수 호출하는 곳이 지역인 경우 주소의 값이 소멸되니까 얘도 없어져 버림. 그래서 데이터까지 복사하는 깊은 복사를 해 줘야 하는 거다.
	// 깊은 복사 하려면 따로 주소 동적할당해서 문자열 복사해 주는 거
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
		printf("Is Empty!\n");
		return;
	}
	SNode* pCurNode = pHead;
	int cnt = 0;
	while (pCurNode != NULL)
	{
		printf("{ % d: % s } - ", pCurNode->key, pCurNode->msg);

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
		SAFE_FREE(pDestroyNode->msg);
		SAFE_FREE(pDestroyNode);
	}
	// SAFE_FREE(pHead);
	// ㄴ 해제를 했는데 값은 null이고 주소 값은 살아있는 상황에서 주소값 또 해제하려고 시도하면 에러난다.
	pHead = NULL;

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