#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N)
{
	// 서로 다른 위치에서 두 원소가 존재하는 경우
	// a + b == 100일때

	/*
	// 시간 복잡도 : O(N^2)
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (arr[i] + arr[j] == 100)
				return 1;
		}
	}
	*/

	/// ** 최적화 하기 **
	// 시간 복잡도 : O(N)
	int myArr[100] = {};
	for (int i = 0; i < N; ++i) {
		if (myArr[100 - arr[i]] != 0)
			return 1;
		else
			myArr[arr[i]]++;
	}

	return 0;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	int arr1[] = { 1,52,48 };
	int arr2[] = { 50,42 };
	int arr3[] = { 4,13,63,87 };
	int arr4[] = { 87, 43, 87, 13 };

	cout << func2(arr1, 3) << '\n';
	cout << func2(arr2, 2) << '\n';
	cout << func2(arr3, 4) << '\n';
	cout << func2(arr4, 4) << '\n';

	return 0;
}
