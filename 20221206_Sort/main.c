#include <stdio.h>
// �����Լ� ���� ���� �ʿ��� ������� 2��
#include <stdlib.h>
#include <time.h> 
#define ARR_LEN 8
//#define DEBUG_SELECTION
//#define DEBUG_INSERTION
#define DEBUG_BUBBLE

void TestNumbers(int* const _pArr, const int const _len);

void SetRandomNumber(int* const _pArr, const int const _len);
void PrintAll(const int* const _pArr, const int const _len);
int FindMinIdxInArr(const int* const _pArr, const int const _len, const int const _startNum);
int FindMinNumInArr(const int* const _pArr, const int const _len, const int const _startNum);

// # ���� ����
void SelectionSort(int* const _pArr, const int const _len);
// # ���� ����
void InsertionSort(int* const _pArr, const int const _len);
// # ��ǰ ����
void BubbleSort(int* const _pArr, const int const _len);
// # �� ����
void QuickSort(int* const _pArr, const int const _len);

void Swap(int* _left, int* _right);

void SortingInDevidedLeftArr(int* _pArr, int _len, int* _lpIdx, int* _devideIdx);

void SortingInDevidedRightArr(int* _pArr, int _len, int* _rpIdx, int* _devideIdx);


int main()
{
	srand(time(NULL));
	int arr[ARR_LEN] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//// # test of ���� ����
	//printf("- SelectionSort -\n");
	//SetRandomNumber(arr, len);
	//PrintAll(arr, len);
	//SelectionSort(arr, len);
	//PrintAll(arr, len);

	//printf("\n");

	//// # test of ���� ����
	//printf("- Insertion Sort - \n");
	//SetRandomNumber(arr, len);
	//PrintAll(arr, len);
	//InsertionSort(arr, len);
	//PrintAll(arr, len);

	//printf("\n");

	//// # test of ��ǰ ����
	//printf("- Bubble Sort - \n");
	//SetRandomNumber(arr, len);
	//PrintAll(arr, len);
	//BubbleSort(arr, len);
	//PrintAll(arr, len);

	//printf("\n");

	// # test of �� ����
	printf(" - Quick Sort -\n");
	//SetRandomNumber(arr, len);
	TestNumbers(arr, len);
	PrintAll(arr, len);
	QuickSort(arr, len);
	PrintAll(arr, len);

	return 0;
} // end of main()

void TestNumbers(int* const _pArr, const int const _len)
{
	if (_pArr == NULL) return;
	_pArr[0] = 50;
	_pArr[1] = 80;
	_pArr[2] = 20;
	_pArr[3] = 90;
	_pArr[4] = 40;
	_pArr[5] = 10;
	_pArr[6] = 30;
	_pArr[7] = 60;
}
void SetRandomNumber(int* const _pArr, const int const _len)
{
	if (_pArr == NULL) return;
	for (int i = 0; i < _len; ++i)
		_pArr[i] = (rand() % 100) + 1;
}
void PrintAll(const int* const _pArr, const int const _len)
{
	if (_pArr == NULL) return;
	for (int i = 0; i < _len; ++i)
		printf("%d - ", _pArr[i]);
	printf("(%d)\n", _len);
}

int FindMinIdxInArr(const int* const _pArr, const int const _len, const int const _startNum)
{
	int minIdx = _startNum;
	for (int i = _startNum + 1; i < _len; ++i)
	{
		//if (_pArr[minIdx] > _pArr[i])
		if (_pArr[i] < _pArr[minIdx])
		{
			minIdx = i;
		}
	}
	return minIdx;
}

int FindMinNumInArr(const int* const _pArr, const int const _len, const int const _startNum)
{
	int minIdx = FindMinIdxInArr(_pArr, _len, _startNum);
	return _pArr[minIdx];
}

void SelectionSort(int* const _pArr, const int const _len)
{
	/*
		- �迭�� ���߿��� ���� ���� �� ã�Ƽ�
		- �� ���ڸ��� �ű��
		�� �ݺ�
	*/
	if (_pArr == NULL || _len == 0) return;
	for (int j = 0; j < _len - 1; j++)
	{
		int minIdx = j;
		// 1. �ּڰ� ã��
		minIdx = FindMinIdxInArr(_pArr, _len, j);
		// 2. �� �ڸ��� ���� ��ȯ
#ifdef DEBUG_SELECTION
		printf("%d(%d) -> %d(%d)\n", minIdx, _pArr[minIdx], 0, _pArr[0]);
#endif // DEBUG_SELECTION

		int tmp = _pArr[minIdx];
		_pArr[minIdx] = _pArr[j];
		_pArr[j] = tmp;
	}
} // end of SelectionSort()
void InsertionSort(int* const _pArr, const int const _len)
{
	if (_pArr == NULL || _len == 0) return;
	for (int j = 0; j < _len - 1; ++j)
	{
		// 1. �ּڰ� ã��
		int minIdx = FindMinIdxInArr(_pArr, _len, j);
		int minVal = _pArr[minIdx];
#ifdef DEBUG_INSERTION
		printf("Min : %d(%d)\n", minIdx, minVal);
#endif
		// 2. ���� ����(�� �б�)
		for (int i = minIdx; i > j; --i)
		{
#ifdef DEBUG_INSERTION
			printf("%d -> %d\n", i - 1, i);
#endif
			_pArr[i] = _pArr[i - 1];
		}
		// 3. �� ������ �ּڰ� ����
		_pArr[j] = minVal;
	}
} // end of InsertionSort()

void BubbleSort(int* const _pArr, const int const _len)
{
	// 1. ���ڸ� ���� ��
	// 2. ������ ���� ������ ������ ũ�� ��ȯ(���������� ��)
	// 3. �迭 ������ �ݺ�

	if (_pArr == NULL || _len == 0) return;

	// ��ü ��ȸ ����
	for (int j = 0; j < _len; j++)
	{
		// �ΰ� �� ����
		for (int i = 0; i < _len - 1 - j; i++)
		{
			int temp = 0;
			if (_pArr[i] > _pArr[i + 1])
			{
				temp = _pArr[i];
				_pArr[i] = _pArr[i + 1];
				_pArr[i + 1] = temp;
#ifdef DEBUG_BUBBLE
				PrintAll(_pArr, _len);
#endif
			}
		}
	}
} // end of BubbleSort()

void QuickSort(int* const _pArr, const int const _len)
{
	// ** pivot : _pArr[0]���� ����.
	if (_pArr == NULL || _len == 0) return;
	int* lpIdx = (int*)malloc(sizeof(int));
	int* rpIdx = (int*)malloc(sizeof(int));
	*lpIdx = 0;
	*rpIdx = 0;
	/*int lhIdx = pIdx + 1;
	int rlIdx = _len - 1;*/
	int* devideIdx = (int*)malloc(sizeof(int));
	*devideIdx = _len / 2;
	// lhIdx <= rlIdx �� ���ȸ� �ݺ�
	// lh��°�� pivot���� ũ�� rl��°�� pivot���� ������ => lh��° ���� rl��° �� ����
	//printf("%d  , %d\n", _pArr[lhIdx], _pArr[rlIdx]);
	//printf("%p  , %p\n", &(_pArr[lhIdx]), &(_pArr[rlIdx]));
	// pIdx�� ��� �ٲ��, devideIdx�� ��� �ٲ�µ�..
	// sorting���� ����? 
	for (int i = 0; i < _len; i++)
	{
		SortingInDevidedLeftArr(_pArr, _len, &lpIdx, &devideIdx);
		SortingInDevidedRightArr(_pArr, _len, &rpIdx, &devideIdx);
		//printf("%d\n", *devideIdx);
		printf("??\n");

	}

}// end of QuickSort()
void Swap(int* _left, int* _right)
{
	int temp = *_left;
	*_left = *_right;
	*_right = temp;
}
// pivot�� �ٲ� idx (������ rlIdx)�������� 
// left�� right�� arr�� devide���ִ� �Լ�.
// �ϴ� ���� �ε����� left Ȥ�� right ���̰� <=1�̸� �׳� return.
// �� ���� �ش� �ȵǴ� left or right�� �ٽ� ����.

void SortingInDevidedLeftArr(int* _pArr, int _len, int* _lpIdx, int* _devideIdx)
{
	if (*_devideIdx == 0)
	{
		printf("*_devideIdx  == 0 => SortingInDevidedLeftArr return�մϴ�.\n");
		return;
	}
	int lhIdx = *_lpIdx + 1;
	int rhIdx = (*_devideIdx) - 1;
	/*
�ƴ� ���Լ� �ݺ��� �ǵ�
devideIdx�� rlIdx�� ������
pivot�� _pArr[0] �̰ų� devideIdx +1
	*/
	if (rhIdx - lhIdx <= 1)
	{
		return;
	}
	while (lhIdx < rhIdx)
	{
		printf("???lhIdx < rhIdx\n");
		if (rhIdx - lhIdx <= 1)
		{
			printf("_rlIdx - _lhIdx <= 1\n");
			return;
		}
		if (_pArr[lhIdx] > _pArr[*_lpIdx] && _pArr[rhIdx] < _pArr[*_lpIdx])
		{
			Swap(&(_pArr[lhIdx]), &(_pArr[rhIdx]));
		}
		if (!(_pArr[lhIdx] > _pArr[*_lpIdx]))
		{
			lhIdx++;
		}
		if (!(_pArr[rhIdx] < _pArr[*_lpIdx]))
		{
			rhIdx--;
		}
		// pivot�̶� rlIdx�� �ٲ��ִ� �ڵ�
		if (lhIdx == rhIdx)
		{
			Swap(&(_pArr[*_lpIdx]), &(_pArr[rhIdx]));
			*_devideIdx = rhIdx;
		}
		*_lpIdx = 
	}
}
void SortingInDevidedRightArr(int* _pArr, int _len, int* _rpIdx, int* _devideIdx)
{
	if (*_devideIdx == _len)
	{
		printf("*_devideIdx  == _len => Right �����մϴ�.\n");
		return;
	}
	int lhIdx = *_devideIdx + 1;
	int rhIdx = _len - 1;

	if (rhIdx - lhIdx <= 1)
	{
		return;
	}
	while (lhIdx < rhIdx)
	{
		printf("???\n");
		if (rhIdx - lhIdx <= 1)
		{
			printf("_rlIdx - _lhIdx <= 1 => SortingInDevidedRightArr return�մϴ�.\n");
			return;
		}
		if (_pArr[lhIdx] > _pArr[*_rpIdx] && _pArr[rhIdx] < _pArr[*_rpIdx])
		{
			Swap(&(_pArr[lhIdx]), &(_pArr[rhIdx]));
		}
		if (!(_pArr[lhIdx] > _pArr[*_rpIdx]))
		{
			lhIdx++;
		}
		if (!(_pArr[rhIdx] < _pArr[*_rpIdx]))
		{
			rhIdx--;
		}
		// pivot�̶� rlIdx�� �ٲ��ִ� �ڵ�
		if (lhIdx == rhIdx)
		{
			Swap(&(_pArr[*_rpIdx]), &(_pArr[rhIdx]));
			*_devideIdx = rhIdx;
		}
	}
}