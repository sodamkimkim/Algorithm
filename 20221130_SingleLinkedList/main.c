#include <stdio.h>
#include <malloc.h>
typedef struct _SNode
{
	int data;
	struct _SNode* pNext;
}SNode;

void Add(const SNode** const _pHead, const int const _data);

// 과제1. 
// 해당 인덱스에 _data삽입
// 원래 있던 건 밀리게 했음
void Insert(const SNode** const _pHead, const int const _idx, const int const _data);
//과제 2.
void RemoveAt(const SNode** const  _pHead, const int const _idx);
// 과제 3.
int Count(const SNode* const _pHead);

void PrintAll(const SNode* const _pHead);
void DestroyAll(SNode** _pHead);

int main()
{
	SNode* pHead = NULL;
	Add(&pHead, 0);
	Add(&pHead, 1);
	Add(&pHead, 2);
	Add(&pHead, 3);
	Insert(&pHead, 0, 222);
	Insert(&pHead, 2, 5555);
	//insert(&pHead, 1, 1111);
	PrintAll(pHead);
	printf("%d개\n", Count(pHead));

	printf("//////////After remove//////////\n");
	printf("Remove index 2\n");
	RemoveAt(&pHead, 2);
	printf("Remove index 0\n");
	RemoveAt(&pHead, 0);
	PrintAll(pHead);
	printf("%d개\n", Count(pHead));
	return 0;
} // end of main

void Add(const SNode** const _pHead, const int const _data)
{
	if (_pHead == NULL) return;
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	pNewNode->data = _data;
	pNewNode->pNext = NULL;
	if (*_pHead == NULL)
	{
		*_pHead = pNewNode;
		return;
	}
	else {
		SNode* pCurNode = *_pHead;
		while (pCurNode->pNext != NULL)
		{
			pCurNode = pCurNode->pNext;
		}
		pCurNode->pNext = pNewNode;
	}
}
void Insert(const SNode** const _pHead, const int const _idx, const int const _data)
{
	if (_pHead == NULL) return;
	SNode* pPrevNode = *_pHead;
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	SNode* pCurNode = *_pHead;
	pNewNode->data = _data;

	int idxTemp = 0;
	if (_idx == 0)
	{
		*_pHead = pNewNode;

	}
	else {
		while (idxTemp != _idx)
		{
			pPrevNode = pCurNode;
			pCurNode = pCurNode->pNext;
			idxTemp++;
		}
		pPrevNode->pNext = pNewNode;
	}
	pNewNode->pNext = pCurNode;
	return;
}
void RemoveAt(const SNode** const _pHead, const int const _idx)
{
	if (_pHead == NULL) return;
	SNode* pPrevNode = *_pHead;
	SNode* pDestroyNode = NULL;
	SNode* pCurNode = *_pHead;
	SNode* pNextNode = *_pHead;
	int idxTemp = 0;
	if (_idx == 0)
	{
		*_pHead = pCurNode->pNext;
	}
	else {
		// 1  2
		while (idxTemp != _idx)
		{
			pPrevNode = pCurNode;
			pDestroyNode = pCurNode;
			pCurNode = pCurNode->pNext;
			idxTemp++;
		}
		pNextNode = pCurNode->pNext;
		pPrevNode->pNext = pNextNode;
	}
	pDestroyNode = NULL;
	free(pDestroyNode);
	return;


}
int Count(const SNode* const _pHead)
{
	int cnt = 0;
	if (_pHead == NULL)
	{
		printf("_pHead is NULL\n");
		cnt = 0;
	}
	else {
		SNode* pTemp = _pHead;
		while (pTemp != NULL)
		{
			++cnt;
			pTemp = pTemp->pNext;
		}
	}
	return cnt;
}
void PrintAll(const SNode* const _pHead)
{
	if (_pHead == NULL)
	{
		return;
	}
	SNode* pCurNode = _pHead;
	int cnt = 0;
	while (pCurNode != NULL)
	{
		printf("%d - ", pCurNode->data);
		pCurNode = pCurNode->pNext;
		++cnt;
	}
	printf("(%d)\n", cnt);
}
void DestroyAll(SNode** _pHead)
{
	SNode* pCurNode = *_pHead;
	while (pCurNode != NULL)
	{
		SNode* pDestroyNode = pCurNode;
		pCurNode = pCurNode->pNext;
		printf("DestroyNode: %d (%p)\n", pDestroyNode->data, pDestroyNode);
		if (pDestroyNode != NULL)
		{
			free(pDestroyNode);
			pDestroyNode = NULL;
		}
	}
	*_pHead = NULL;
}
