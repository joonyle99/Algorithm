#include <bits/stdc++.h>
using namespace std;

void SelectSort(vector<int>& arr, int n)
{
	// 선택 정렬 O(N^2)
	// 버블 정렬에 비해 상대적으로 교환(swap) 횟수가 적다
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i; j < n; ++j) {
			// 이 작업은 정렬 상태와 상관없이 상수로 실행되는 코드이다
			if (arr[minIndex] > arr[j]) minIndex = j;
		}
		if (minIndex != i) swap(arr[minIndex], arr[i]);
	}
}

void BubbleSort(vector<int>& arr, int n)
{
	// 버블 정렬 O(N^2)
	// 거의 정렬된 상태라면 선택 정렬 보다 빠르다
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			// 정렬 상태에 따라 코드 실행이 스킵될 수 있다
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

void MergeSort(vector<int>& arr1, vector<int>& arr2, int n)
{
	// 하나의 정렬된 리스트로 합치는 병합 정렬 알고리즘의 핵심 단계
	// cf ) 그걸 그냥 하나로 합쳐버리고 한번에 버블 정렬로 한다면 O((N + M) ^ 2)
	// -> 아래와 같이 정석대로 한다면 O(N + M)으로 할 수 있다 (선형적으로 해결이 가능하다)
	vector<int> arr12(n);
	int arr1Index = 0;
	int arr2Index = 0;
	int arr12Index = 0;
	while (arr12Index != n) {

		if (arr1Index >= arr1.size()) {
			arr12[arr12Index] = arr2[arr2Index++];
		}
		else if (arr2Index >= arr2.size()) {
			arr12[arr12Index] = arr1[arr1Index++];
		}
		else
		{
			if (arr1[arr1Index] >= arr2[arr2Index]) {		// >가 아닌 >=로 해준다. 정렬은 잘 실행되지만 Stable Sort 때문
				arr12[arr12Index] = arr2[arr2Index++];
			}
			else {
				arr12[arr12Index] = arr1[arr1Index++];
			}
		}

		arr12Index++;
	}
}


int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int n = 10;

	int thisCount = n / 2;
	int otherCount = n - thisCount;

	// 두 리스트 만들기
	vector<int> arr1(thisCount);
	for (int i = 0; i < thisCount; ++i) {
		arr1[i] = rand();
	}
	vector<int> arr2(otherCount);
	for (int i = 0; i < thisCount; ++i) {
		arr1[i] = rand();
	}

	// 정렬된 두 리스트
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());


	return 0;
}
