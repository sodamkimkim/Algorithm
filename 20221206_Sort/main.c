#include <stdio.h>
// 랜덤함수 쓰기 위해 필요한 헤더파일 2개
#include <stdlib.h>
#include <time.h> 
#define ARR_LEN 5
//#define DEBUG_SELECTION
//#define DEBUG_INSERTION
#define DEBUG_BUBBLE

void TestNumbers(int* const _pArr, const int const _len);

void SetRandomNumber(int* const _pArr, const int const _len);
void PrintAll(const int* const _pArr, const int const _len);
int FindMinIdxInArr(const int* const _pArr, const int const _len, const int const _startNum);
int FindMinNumInArr(const int* const _pArr, const int const _len, const int const _startNum);

// # 선택 정렬
void SelectionSort(int* const _pArr, const int const _len);
// # 삽입 정렬
void InsertionSort(int* const _pArr, const int const _len);
// # 거품 정렬
void BubbleSort(int* const _pArr, const int const _len);
// # 퀵 정렬
void QuickSort(int* const _pArr, const int const _left, const int const _right);
int Partition(int* const _pArr, int _left, int _right);

void Swap(int* _left, int* _right);

void SortingInDevidedLeftArr(int* _pArr, int _len, int* _lpIdx, int* _devideIdx);

void SortingInDevidedRightArr(int* _pArr, int _len, int* _rpIdx, int* _devideIdx);


int main()
{
	srand(time(NULL));
	int arr[ARR_LEN] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//// # test of 선택 정렬
	//printf("- SelectionSort -\n");
	//SetRandomNumber(arr, len);
	//PrintAll(arr, len);
	//SelectionSort(arr, len);
	//PrintAll(arr, len);

	//printf("\n");

	//// # test of 삽입 정렬
	//printf("- Insertion Sort - \n");
	//SetRandomNumber(arr, len);
	//PrintAll(arr, len);
	//InsertionSort(arr, len);
	//PrintAll(arr, len);

	//printf("\n");

	//// # test of 거품 정렬
	//printf("- Bubble Sort - \n");
	//SetRandomNumber(arr, len);
	//PrintAll(arr, len);
	//BubbleSort(arr, len);
	//PrintAll(arr, len);

	//printf("\n");

	// # test of 퀵 정렬
	printf(" - Quick Sort -\n");
	//SetRandomNumber(arr, len);
	//TestNumbers(arr, len);
	int qArr[7] = { 5,1,7,4,3,2,6 };
	int qLen = 7;
	PrintAll(qArr, qLen);
	QuickSort(qArr, 0, qLen - 1);
	PrintAll(qArr, qLen);

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
		- 배열의 값중에서 가장 작은 값 찾아서
		- 젤 앞자리로 옮기기
		ㄴ 반복
	*/
	if (_pArr == NULL || _len == 0) return;
	for (int j = 0; j < _len - 1; j++)
	{
		int minIdx = j;
		// 1. 최솟값 찾기
		minIdx = FindMinIdxInArr(_pArr, _len, j);
		// 2. 앞 자리의 값과 교환
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
		// 1. 최솟값 찾기
		int minIdx = FindMinIdxInArr(_pArr, _len, j);
		int minVal = _pArr[minIdx];
#ifdef DEBUG_INSERTION
		printf("Min : %d(%d)\n", minIdx, minVal);
#endif
		// 2. 공간 마련(값 밀기)
		for (int i = minIdx; i > j; --i)
		{
#ifdef DEBUG_INSERTION
			printf("%d -> %d\n", i - 1, i);
#endif
			_pArr[i] = _pArr[i - 1];
		}
		// 3. 빈 공간에 최솟값 삽입
		_pArr[j] = minVal;
	}
} // end of InsertionSort()

void BubbleSort(int* const _pArr, const int const _len)
{
	// 1. 옆자리 값과 비교
	// 2. 왼쪽의 값이 오른쪽 값보다 크면 교환(오름차순일 때)
	// 3. 배열 끝까지 반복

	if (_pArr == NULL || _len == 0) return;

	// 전체 순회 포문
	for (int j = 0; j < _len; j++)
	{
		// 두개 비교 포문
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

void QuickSort(int* _pArr, int _left, int _right)
{
	if (_left < _right)
	{
		int idx = Partition(_pArr, _left, _right);
		QuickSort(_pArr, _left, idx - 1);
		QuickSort(_pArr, idx + 1, _right);

	}
}

int Partition(int* const _pArr, int _left, int _right)
{
	int first = _left; // 정렬 대상 배열의 첫번째 인덱스는 _left가 되고, 
	int pivot = _pArr[first]; // _pArr[_left]가 pivot이 됨
	++_left; // pivot값 할당 한 후에 _left의 본업 수행을 위해 ++_left해줌

	while (_left <= _right)
	{
		while (_pArr[_left] <= pivot && _left < _right)
			++_left;
		while (_pArr[_right] >= pivot && _left <= _right)
			--_right;
		if (_left < _right) // 위의 while다 돌았는데 _left < _right이면 swap. 아니면 break;
			Swap(&_pArr[_left], &_pArr[_right]);
		else
			break;
	}
	Swap(&_pArr[first], &_pArr[_right]);
	return _right;
}

void Swap(int* _left, int* _right)
{
	int temp = *_left;
	*_left = *_right;
	*_right = temp;
}

void SortingInDevidedLeftArr(int* _pArr, int _len, int* _lpIdx, int* _devideIdx)
{
	if (*_devideIdx == 0)
	{
		printf("*_devideIdx  == 0 => SortingInDevidedLeftArr return합니다.\n");
		return;
	}
	int lhIdx = *_lpIdx + 1;
	int rhIdx = (*_devideIdx) - 1;

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
		// pivot이랑 rlIdx랑 바꿔주는 코드
		if (lhIdx == rhIdx)
		{
			Swap(&(_pArr[*_lpIdx]), &(_pArr[rhIdx]));
			*_devideIdx = rhIdx;
		}

	}
}
