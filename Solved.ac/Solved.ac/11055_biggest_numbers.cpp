#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];
int dp[1005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 가장 큰 증가하는 부분 수열

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];	// 초기화
	}

	// dp[i]: i요소까지의 최대 부분합을 저장해둔다 ** 첫째: 이 발상도 어렵다 **

	// O(N^2)이지만 N = 1000이기 때문에 1초 안에 충분히 해결할 수 있다
	// 10^6 = 100만 -> 1초 안에 쌉 가능

	// i 요소를 마지막 요소로 두고
	for (int i = 0; i < N; i++) {
		// 앞에 있는 요소들의 부분합을 저장한다
		for (int j = 0; j < i; j++) {
			// 작은 경우에만 부분합 계산
			if (arr[i] > arr[j]) {
				// j요소가 i요소보다 작기 때문에, 연쇄적으로 dp[i]를 구하기 위해 dp[j]의 값을 사용할 수 있는 것이다.. ** 둘째: 이 발상은 더 어렵다 **
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}

	std::cout << *max_element(dp, dp + N);

	return 0;
}
