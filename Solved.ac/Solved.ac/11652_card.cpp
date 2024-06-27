#include <bits/stdc++.h>
using namespace std;

int N;
long long cards[100005];

// 256MB = 256x 10^6 Byte
// 256 / 4 = 64
// 64 x 10^6개의 요소를 가진 배열을 선언할 수 있음
// 1 x 10^5개의 요소쯤은 끄떡 없음

void Solution1() {	// O(N^2)

	// 가장 많이 가지고 있는 카드에 적힌 정수
	long long most_frequent_number = cards[0];

	// 그 정수가 나온 횟수
	int maxCount = 1;

	// 카드를 순회한다
	for (int i = 0; i < N; i++) {
		int count = 1;
		// 해당 인덱스의 카드와 동일한 정수가 적힌 카드를 발견하면 개수를 증가시킨다.
		for (int j = 0; j < N; j++) {
			if (cards[i] == cards[j]) {
				count++;
			}
		}
		// 개수가 더 많아졌으면 개수와 정수를 갱신한다
		if (count > maxCount) {
			maxCount = count;
			most_frequent_number = cards[i];
		}
		// 같더라도 이전 정수보다 더 작다면 갱신한다
		else if (count == maxCount && cards[i] < most_frequent_number) {
			most_frequent_number = cards[i];
		}
	}

	cout << most_frequent_number;
}

void Solution2() {

	// 오름차순으로 정렬된 상태의 배열을 만든다
	std::sort(cards, cards + N);

	// 첫번째 요소를 넣는다
	long long most_freq_num = cards[0];

	int maxCount = 0;
	int curCount = 1;	// 첫번재 요소의 개수는 이미 셌다

	// 카드를 순회한다
	for (int i = 1; i < N; i++) {
		// 연속된 같은 숫자들에 대해서 개수를 증가시킨다
		if (cards[i] == cards[i - 1])
			curCount++;
		// 연속하지 않은 숫자가 등장했다면
		else {
			// 그리고 그동안 쌓아온 개수가 최대 개수보다 크다면 갱신한다
			if (maxCount < curCount) {
				maxCount = curCount;
				most_freq_num = cards[i - 1];
			}
			curCount = 1;
		}
	}

	// 마지막 연속된 숫자 그룹 처리
	if (maxCount < curCount) {
		maxCount = curCount;
		most_freq_num = cards[N - 1];
	}

	cout << most_freq_num;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 카드

	/// 정렬을 이용해서 시간복잡도를 크게 줄일 수 있는 문제

	// 1. counting sort로 풀기에는 배열의 길이가 감당이 안된다.
	// 2. 왜 O(N^2)의 풀이를 떠올리지 못했지? 바본가?

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	// Solution1();
	Solution2();

	return 0;
}
