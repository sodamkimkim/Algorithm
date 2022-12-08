#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 10
//#define DEBUG_SELECTION
//#define DEBUG_INSERTION
//#define DEBUG_BUBBLE
//#define DEBUG_QUICK

void SetRandomNumber(int* _pArr, int _len);
void PrintAll(int* _pArr, int _len);
void Swap(int* _left, int* _right);

// # ������
void QuickSort(int* _pArr, int _len, int _startIdx, int _endIdx);
int Partition(int* _pArr, int _len, int _startIdx, int _endIdx);

int main()
{
	srand((unsigned int)time(NULL));

	int arr[ARR_LEN] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	// ������
	printf("- Quick Sort -\n");
	SetRandomNumber(arr, len);
	PrintAll(arr, len);
	QuickSort(arr, len, 0, len - 1);
	PrintAll(arr, len);

	//int qArr[9] = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
	//int qLen = 9;
	//PrintAll(qArr, qLen);
	//QuickSort(qArr, qLen, 0, qLen - 1);
	//PrintAll(qArr, qLen);

	return 0;
}

void SetRandomNumber(int* _pArr, int _len)
{
	if (_pArr == NULL || _len == 0) return;

	for (int i = 0; i < _len; ++i)
		_pArr[i] = (rand() % 100) + 1;
}

void PrintAll(int* _pArr, int _len)
{
	if (_pArr == NULL || _len == 0) return;

	for (int i = 0; i < _len; ++i)
		printf("%d - ", _pArr[i]);
	printf("(%d)\n", _len);
}

void Swap(int* _left, int* _right)
{
	int temp = *_left;
	*_left = *_right;
	*_right = temp;
}

void QuickSort(int* _pArr, int _len, int _startIdx, int _endIdx)
{
	if (_pArr == NULL || _len == 0) return;
	if (_startIdx >= _endIdx) return;

	int curPivotIdx = Partition(_pArr, _len, _startIdx, _endIdx);

	QuickSort(_pArr, _len, _startIdx, curPivotIdx - 1);
	QuickSort(_pArr, _len, curPivotIdx + 1, _endIdx);
}

int Partition(int* _pArr, int _len, int _startIdx, int _endIdx)
{
	if (_pArr == NULL || _len == 0) return;

	int pivotIdx = _startIdx;
	int leftIdx = _startIdx + 1;
	int rightIdx = _endIdx;
	const int startIdx = leftIdx;
	const int endIdx = rightIdx;

	// ���� �ε����� ������ �ε����� ���� �� �� ���� �ݺ�
	while (leftIdx < rightIdx)
	{
		// 1. ���� �ε����� �迭�� ������ �̵�
		//    �Ǻ� �� ���� ū ���� ���� �� ���� ���������� �̵�
		while ((leftIdx < endIdx) &&
			(_pArr[leftIdx] <= _pArr[pivotIdx]))
		{
			++leftIdx;
		}
		// 2. ������ �ε����� �迭�� ���۱��� �̵�
		//    �Ǻ� �� ���� ���� ���� ���� �� ���� �������� �̵�
		while ((rightIdx > startIdx) &&
			(_pArr[rightIdx] >= _pArr[pivotIdx]))
		{
			--rightIdx;
		}

		// �� �ε����� ������ �ߴٸ� ����
		if (leftIdx > rightIdx) break;

		// 3. ���� ���� ������ �� ��ȯ
		Swap(&_pArr[leftIdx], &_pArr[rightIdx]);

	} // while

	// 4. ������ �ε��� ���� �Ǻ� �� ��ȯ
	if (_pArr[pivotIdx] > _pArr[rightIdx])
	{
		Swap(&_pArr[rightIdx], &_pArr[pivotIdx]);

		// ���� �Ǻ� ���� ���ִ� �ε���
		return rightIdx;
	}
	return pivotIdx;
}
