#include <stdio.h>
#include <malloc.h>

typedef struct _SNode
{
	int data;
	struct _SNode* pPrev;
	struct _SNode* pNext;
}SNode;
SNode head;
SNode tail;

//void Add(int _data);
void Add(SNode* const _pNewNode);

int Count();
// 과제
void Insert(const int const _idx, const SNode* const _pNewNode);
// 과제
void RemoveAt(const int const _idx);
// 과제
void DestroyAll();
void PrintAll();
SNode* CreateNode(const int const _data);

int main()
{
	head.pPrev = NULL;
	head.pNext = &tail;
	tail.pPrev = &head;
	tail.pNext = NULL;
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	pNewNode->data = 1;
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL;
	Add(pNewNode);
	Add(CreateNode(2));
	Add(CreateNode(3));
	PrintAll();
	printf("%d개\n", Count());

	return 0;
}
void Add(SNode* const _pNewNode)
{
	if (_pNewNode == NULL) return;
	_pNewNode->pPrev = tail.pPrev;
	_pNewNode->pNext = &tail;
	tail.pPrev->pNext = _pNewNode;
	tail.pPrev = _pNewNode;
}
int Count()
{
	SNode* pCurNode = head.pNext;
	int cnt = 0;
	while (pCurNode != &tail)
	{
		pCurNode = pCurNode->pNext;
		cnt++;
	}
	return cnt;
}

void PrintAll()
{
	SNode* pCurNode = head.pNext;
	int cnt = 0;
	while (pCurNode != &tail)
	{
		printf("%d - ", pCurNode->data);
		pCurNode = pCurNode->pNext;
		++cnt;
	}
	printf("(%d)\n", cnt);
}

SNode* CreateNode(const int const _data)
{
	SNode* pNode = (SNode*)malloc(sizeof(SNode));
	pNode->data = _data;
	pNode->pPrev = NULL;
	pNode->pNext = NULL;
	return pNode;
}