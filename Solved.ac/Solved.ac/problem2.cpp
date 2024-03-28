#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int len)
{
	int myArray[101];

	for (int i = 0; i < len; ++i)
	{
		if (myArray[100 - arr[i]] == 1) return 1;
		myArray[arr[i]] = 1;
	}

	return 0;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ¹®Á¦ 2

	int arr[1000] = { 1,52,48 };
	int len = 3;

	int arr1[1000] = { 50, 42 };
	int len1 = 2;

	int arr2[1000] = { 4, 13, 63, 87 };
	int len2 = 4;

	cout << func2(arr, len) << '\n';
	cout << func2(arr1, len1) << '\n';
	cout << func2(arr2, len2) << '\n';

	return 0;
}
