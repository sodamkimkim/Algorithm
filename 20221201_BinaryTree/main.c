#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

typedef struct _SNode
{
	int data;
	struct _SNode* pLeft;
	struct _SNode* pRight;
}SNode;

void Add(const SNode** const _pHead, const int const _data);
void PrintAll(const SNode* const _pHead);
void PrintRecursive(const SNode* const _pNode);
void DestroyAll(const SNode** const _pHead);
void DestroyRecursive(const SNode** const _pNode);

// 과제0
int CountTotal(SNode* _pHead);
// 과제1
int CountLeft(SNode* _pHead);
// 과제 2
int CountRight(SNode* _pHead);
// 과제 3
// 트리의 특정 레벨만 출력하는 함수
/*
ex)
	 7  -lev1
4        9   -lev2
*/
int PrintLevel(SNode* _pHead, int _level);
int main()
{
	// 랜덤숫자 출력
	// random seed값에 따라서 다른 난수가 발생된다.
	// 시간을 seed값으로 쓰면 매번 다른 값을 출력할 수 있다.
	srand(time(NULL));
	// 0~10 사이 값을 얻고 싶으면 나머지 연산자 이용하면 된다.
	// 150 ~160이면 이 값에서 더하기 150 해주면 되고 함수로 빼놓고 쓰면 된다.
	printf("%d\n", rand() % 10);

	SNode* pHead = NULL;
	for (int i = 0; i < 10; ++i)
		Add(&pHead, rand() % 100);


	PrintAll(pHead);
	DestroyAll(&pHead);
	return 0;
}
void Add(const SNode** const _pHead, const int const _data)
{
	if (_pHead == NULL)return;
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	pNewNode->data = _data;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	if (*_pHead == NULL)
	{
		*_pHead = pNewNode;
		printf("Head(%d)\n", _data);
		return;
	}
	SNode* pCurNode = *_pHead;
	printf("(%d) - ", pNewNode->data);
	while (1)
	{
		if (pNewNode->data < pCurNode->data)
		{
			//왼쪽으로 이동
			printf("L - ");
			if (pCurNode->pLeft == NULL)
			{
				printf("LE\n");
				pCurNode->pLeft = pNewNode;
				break;
			}
			else
			{
				pCurNode = pCurNode->pLeft;
				continue;
			}
		}
		else {
			//오른쪽으로 이동
			printf("R - ");
			if (pCurNode->pRight == NULL)
			{
				printf("RE\n");
				pCurNode->pRight = pNewNode;
				break;
			}
			else {
				pCurNode = pCurNode->pRight;
				continue;
			}
		}
	}
}
void PrintAll(const SNode* const _pHead)
{
	if (_pHead == NULL)return;
	PrintRecursive(_pHead);
	printf("\n");
}
void PrintRecursive(const SNode* const _pNode)
{
	if (_pNode == NULL)return;
	PrintRecursive(_pNode->pLeft);
	printf("%d - ", _pNode->data);
	PrintRecursive(_pNode->pRight);

}
void DestroyAll(const SNode** const _pHead) {
	DestroyRecursive(_pHead);
}
void DestroyRecursive(const SNode** const _pNode)
{
	if ((*_pNode) == NULL)return;
	DestroyRecursive(&((*_pNode)->pLeft));
	DestroyRecursive(&((*_pNode)->pRight));

	if ((*_pNode) != NULL)
	{
		printf("Destroy(%d)\n", (*_pNode)->data);
		free((*_pNode));
		(*_pNode) = NULL;
	}
}