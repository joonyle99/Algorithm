#include <bits/stdc++.h>
using namespace std;

int N;
string serialNumbers[55];

/// <summary>
/// compare 함수는 두 인자 a와 b를 받아서 '어느 것이 앞에 와야 하는지' 결정합니다.
/// 내림차순 정렬의 경우(큰 값이 왼쪽에 와야하는 경우), a > b인 경우 true를 반환하여 a가 b보다 앞에 오도록 합니다.
/// 정렬 함수가 여러 번 compare 함수를 호출하여 모든 요소를 정렬합니다.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
bool cmp(const string& a, const string& b) {

	// 배열의 길이 미리 저장
	int aLength = a.length();
	int bLength = b.length();

	// 조건 1: A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
	if (aLength != bLength)
		return aLength < bLength;		// 짧은 게 왼쪽에 위치해야 한다는 뜻
	else {
		// 조건 2
		// : A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서
		// 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
		int aSum = 0, bSum = 0;
		for (int i = 0; i < aLength; i++) {
			if (isdigit(a[i])) {		// 숫자로 변환해주지 않으면 문자의 정수값을 더해버린다 (0도 48을 더해버림)
				aSum += a[i] - '0';
			}
		}
		for (int i = 0; i < bLength; i++) {
			if (isdigit(b[i])) {
				bSum += b[i] - '0';
			}
		}
		if (aSum != bSum)
			return aSum < bSum;			// 합이 작은 게 왼쪽에 위치해야 한다는 뜻
		// 조건 3: 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
		else {
			int minLength = aLength < bLength ? aLength : bLength;
			for (int i = 0; i < minLength; i++) {
				if (a[i] != b[i]) {
					return a[i] < b[i];	// 사전순으로 작은 게 왼쪽에 위치해야 한다는 뜻
				}
			}
			return a[0] < b[0];
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 시리얼 번호

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> serialNumbers[i];
	}

	std::sort(serialNumbers, serialNumbers + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << serialNumbers[i] << '\n';
	}

	return 0;
}
