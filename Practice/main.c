#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_LEN 10

void SetRandomNumber(int* const _pArr, const int const _len);
void PrintAll(const int* const _pArr, const int const _len);
void Swap(int* _left, int* _right);

void QuickSort(int* const _pArr, const int const _len, const int const _startIdx, const int const _endIdx);
int Partition(int* const _pArr, const int const _len, int _leftIdx, int _rightIdx);
int main()
{
	srand(time(NULL));
	int arr[ARR_LEN] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	SetRandomNumber(arr, len);
	PrintAll(arr, len);
	QuickSort(arr, len, 0, len - 1);
	PrintAll(arr, len);

	return 0;
}
void SetRandomNumber(int* const _pArr, const int const _len)
{
	if (_pArr == NULL || _len == 0) return;
	for (int i = 0; i < _len; i++)
		_pArr[i] = (rand() % 100) + 1;
}
void PrintAll(const int* const _pArr, const int const _len)
{
	for (int i = 0; i < _len; i++)
		printf("%d - ", _pArr[i]);
	printf("(%d)\n", _len);
}

void Swap(int* _left, int* _right)
{
	int temp = *_left;
	*_left = *_right;
	*_right = temp;
}

void QuickSort(int* const _pArr, const int const _len, const int const _startIdx, const int const _endIdx)
{
	if (_pArr == NULL || _len == 0) return;
	if (_startIdx >= _endIdx) return;
	int curPivot = Partition(_pArr, _len, _startIdx, _endIdx);
	QuickSort(_pArr, _len, _startIdx, curPivot - 1);
	QuickSort(_pArr, _len, curPivot+1, _endIdx);
}

int Partition(int* const _pArr, const int const _len, const int const _startIdx, const int const _endIdx)
{
	if (_pArr == NULL || _len == 0) return;
	int pivotIdx = _startIdx;
	// 왼 <-> 오 움직이는 인덱스 변수 ㄱ
	int leftIdx = _startIdx + 1;
	int rightIdx = _endIdx;

	const int startIdx = leftIdx;
	const int endIdx = rightIdx;

	// while에서 인덱스 변수들 움직이면서 배열내 숫자들 정렬
	while (leftIdx < rightIdx)
	{
		// 1. 왼쪽 인덱스가 피봇 값보다 큰 값이 나올 떄까지 오른쪽으로 이동 ~ 배열 끝까지 이동
		while (leftIdx < endIdx &&(_pArr[leftIdx] <= _pArr[pivotIdx]))
		{
			++leftIdx;
		}
		// 2. 오른쪽 인덱스가 피봇 값보다 작은 값이 나올 때까지 왼쪽으로 이동 ~ 배열 시작까지 이동
		while (rightIdx > startIdx && (_pArr[rightIdx] >= _pArr[pivotIdx]))
		{
			--rightIdx;
		}
		// ** 두 인덱스가 교차 했다면 종료
		if (leftIdx > rightIdx) break;

		// 3. 왼쪽 값과 오른쪽 값 교환
		Swap(&_pArr[leftIdx], &_pArr[rightIdx]);
	} // while

	// 4. 오른쪽 인덱스 값과 피봇 값 교환.
	//모두 정렬 후, 오른쪽 인덱스 값과 피봇 값 교환조건에 맞으면 (p값>rIdx값) 교환 수행
	if (_pArr[pivotIdx] > _pArr[rightIdx])
	{
		Swap(&_pArr[pivotIdx], &_pArr[rightIdx]);
		// 현재 피봇값이 들어간 인덱스.
		// 파티션 기준이 됨
		return rightIdx;
	}
	return pivotIdx;
}
