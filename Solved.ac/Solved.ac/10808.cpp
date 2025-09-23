#include <bits/stdc++.h>
using namespace std;

string s;
//char arr[26];
int arr[26] = { 0, }; // arr의 index를 알파벳과 대응하는 방식을 사용한다
					// 1. index - alphabet
					// 2. value - count

int main()
{
	// Disconnects C and C++ streams. (printf and cout cannot be mixed.)
	std::ios::sync_with_stdio(false);

	// Do not flush the cout buffer before receiving input with cin.
	std::cin.tie(nullptr);

	// Title : 알파벳 개수

	// Algorithm : 배열

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		int alphabet = (int)s[i] - 'a';
		arr[alphabet]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}
