#include <stdio.h>
// 랜덤함수 쓰기 위해 필요한 헤더파일 2개
#include <stdlib.h>
#include <time.h> 
#define ARR_LEN 5
#define DEBUG_SELECTION
#define DEBUG_INSERTION

void SetRandomNumber(int* const _pArr, const int const _len);
void PrintAll(const int* const _pArr, const int const _len);
// 선택 정렬
void SelectionSort(int* const _pArr, const int const _len);
// 삽입 정렬
void InsertionSort(int* const _pArr, const int const _len);
int main()
{
	srand(time(NULL));
	int arr[ARR_LEN] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	// # test of 선택 정렬
	printf("- SelectionSort -\n");
	SetRandomNumber(arr, len);
	PrintAll(arr, len);
	SelectionSort(arr, len);
	PrintAll(arr, len);

	printf("\n");

	// # test of 삽입 정렬
	printf("- Insertion Sort - \n");
	SetRandomNumber(arr, len);
	PrintAll(arr, len);
	InsertionSort(arr, len);
	PrintAll(arr, len);

	return 0;
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
		for (int i = j + 1; i < _len; ++i)
		{
			//if (_pArr[minIdx] > _pArr[i])
			if (_pArr[i] < _pArr[minIdx])
			{
				minIdx = i;
			}
		}
		// 2. 앞 자리의 값과 교환
#ifdef DEBUG_SELECTION
		printf("%d(%d) -> %d(%d)\n", minIdx, _pArr[minIdx], 0, _pArr[0]);
#endif // DEBUG_SELECTION

		int tmp = _pArr[minIdx];
		_pArr[minIdx] = _pArr[j];
		_pArr[j] = tmp;
	}
}

void InsertionSort(int* const _pArr, const int const _len)
{
	if (_pArr == NULL || _len == 0) return;
	// 1. 최솟값 찾기
	for (int j = 0; j < _len - 1; j++) {
		int temp = 0;
		int minIdx = j;
		for (int i = j + 1; i < _len; ++i)
		{
			//if (_pArr[minIdx] > _pArr[i])
			if (_pArr[i] < _pArr[minIdx])
			{
				minIdx = i;
			}

			temp = _pArr[minIdx];
		}
		// 2. 공간 마련(값 밀기)
		for (int z = 0; z < minIdx - j; z++)
		{
			_pArr[minIdx - z] = _pArr[minIdx - z - 1];
		}
		// 3. 빈 공간에 최솟값 삽입
		_pArr[j] = temp;


	}


}
