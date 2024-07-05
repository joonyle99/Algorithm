#include <bits/stdc++.h>
using namespace std;

int N;
int sequence[1005];
int dp[1005];

int longest_increasing_subsequence(const int* arr) {

	// dp[i]: i번째 원소를 마지막 원소로 하는 가장 긴 증가하는 부분 수열의 길이
	// 
	// dp[1]: 1
	// dp[2]: 2
	// dp[3]: 1
	// dp[4]: 3
	// dp[5]: 2
	// dp[6]: 4

	std::fill(dp + 1, dp + N + 1, 1);

	// O(N^2)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {	// j는 i보다 한 칸 전까지만 탐색해야 하므로 j < i
			// 이 부분이 핵심이다
			// dp[i]: i번째 원소까지의 현재 계산된 LIS 길이
			// dp[j] + 1: j번째 원소까지의 LIS에 '현재 i번째 원소를 추가'한 길이
			if (arr[i] > arr[j]) {	// 1 ~ i까지 중 작은 원소에 대해서만 체크
				// [10 20 10 30 20 50] 이 주어졌을 때
				// i가 4라면 4번째 원소 30을 기준으로,
				// ** 10, 20 10에서의 LIS값 + 1 중 가장 큰 값을 dp[i]로 한다 **
				// * 만약 하나도 없다면 dp[i]의 기본값 (1)을 사용한다 *
				// 이 모든 조건이 이 한줄로 정리된다..
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp + 1, dp + N + 1);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 가장 긴 증가하는 부분 수열 (LIS 문제: Longest Increasing SubSequence)

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sequence[i];
	}
	cout << longest_increasing_subsequence(sequence);

	return 0;
}
