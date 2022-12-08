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
	// �� <-> �� �����̴� �ε��� ���� ��
	int leftIdx = _startIdx + 1;
	int rightIdx = _endIdx;

	const int startIdx = leftIdx;
	const int endIdx = rightIdx;

	// while���� �ε��� ������ �����̸鼭 �迭�� ���ڵ� ����
	while (leftIdx < rightIdx)
	{
		// 1. ���� �ε����� �Ǻ� ������ ū ���� ���� ������ ���������� �̵� ~ �迭 ������ �̵�
		while (leftIdx < endIdx &&(_pArr[leftIdx] <= _pArr[pivotIdx]))
		{
			++leftIdx;
		}
		// 2. ������ �ε����� �Ǻ� ������ ���� ���� ���� ������ �������� �̵� ~ �迭 ���۱��� �̵�
		while (rightIdx > startIdx && (_pArr[rightIdx] >= _pArr[pivotIdx]))
		{
			--rightIdx;
		}
		// ** �� �ε����� ���� �ߴٸ� ����
		if (leftIdx > rightIdx) break;

		// 3. ���� ���� ������ �� ��ȯ
		Swap(&_pArr[leftIdx], &_pArr[rightIdx]);
	} // while

	// 4. ������ �ε��� ���� �Ǻ� �� ��ȯ.
	//��� ���� ��, ������ �ε��� ���� �Ǻ� �� ��ȯ���ǿ� ������ (p��>rIdx��) ��ȯ ����
	if (_pArr[pivotIdx] > _pArr[rightIdx])
	{
		Swap(&_pArr[pivotIdx], &_pArr[rightIdx]);
		// ���� �Ǻ����� �� �ε���.
		// ��Ƽ�� ������ ��
		return rightIdx;
	}
	return pivotIdx;
}
