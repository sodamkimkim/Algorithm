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

// # 퀵정렬
void QuickSort(int* _pArr, int _len, int _startIdx, int _endIdx);
int Partition(int* _pArr, int _len, int _startIdx, int _endIdx);

int main()
{
	srand((unsigned int)time(NULL));

	int arr[ARR_LEN] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	// 퀵정렬
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

	// 왼쪽 인덱스와 오른쪽 인덱스가 교차 할 때 까지 반복
	while (leftIdx < rightIdx)
	{
		// 1. 왼쪽 인덱스가 배열의 끝까지 이동
		//    피봇 값 보다 큰 값이 나올 때 까지 오른쪽으로 이동
		while ((leftIdx < endIdx) &&
			(_pArr[leftIdx] <= _pArr[pivotIdx]))
		{
			++leftIdx;
		}
		// 2. 오른쪽 인덱스가 배열의 시작까지 이동
		//    피봇 값 보다 작은 값이 나올 때 까지 왼쪽으로 이동
		while ((rightIdx > startIdx) &&
			(_pArr[rightIdx] >= _pArr[pivotIdx]))
		{
			--rightIdx;
		}

		// 두 인덱스가 교차를 했다면 종료
		if (leftIdx > rightIdx) break;

		// 3. 왼쪽 값과 오른쪽 값 교환
		Swap(&_pArr[leftIdx], &_pArr[rightIdx]);

	} // while

	// 4. 오른쪽 인덱스 값과 피봇 값 교환
	if (_pArr[pivotIdx] > _pArr[rightIdx])
	{
		Swap(&_pArr[rightIdx], &_pArr[pivotIdx]);

		// 현재 피봇 값이 들어가있는 인덱스
		return rightIdx;
	}
	return pivotIdx;
}
