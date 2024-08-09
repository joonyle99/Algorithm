#include <bits/stdc++.h>
using namespace std;

int N, K;
int c[10];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 동전 0

	// 주어진 동전이 배수 관계에 있다는 조건 덕분에 그리디 알고리즘을 용할 수 있지
	// 만약 조건이 없었다면 1, 9, 10 동전이 주어지고 18원을 만들어야 하면
	// 10원 동전부터 사용해 버리면 총 9번의 동전이 사용된다..

	/// 즉 사소한 조건의 변화에도 민감하기 때문에 '그리디 알고리즘'은 조심해서 사용해야 한다

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> c[i];
	}

	int res = 0;

	/*방법 1*/

	/*
	for (int i = N - 1; i >= 0; --i) {
		// c[i] 동전으로 살 수 있는 만큼 구매
		// while 루프의 최대 반복 횟수는 K / c[i]
		// 
		// while 루프의 실행 횟수는 고정된 N과 같은 다른 변수에 독립적이지 않고,
		// 현재의 금액 'K'와 현재 동전의 가치 'c[i]'에 의해 결정 (계속해서 K의 값이 작아진다)
		while (K - c[i] >= 0) {
			K -= c[i];
			res++;
		}
	}
	
	// 외부 for 루프: N번 반복, O(N)
	// 내부 while 루프: 최악의 경우 K번 반복할 수 있음, O(K)

	// 전체 복잡도: O(N + K)
	// (각 동전에 대해 최대 K번의 연산을 수행할 수 있지만, 실제로는 '모든 동전에 대해 합쳐서' 최대 K번의 연산만 수행됩니다.)
	*/

	/*방법 2*/

	for (int i = N - 1; i >= 0; --i) {
		res += K / c[i];
		K %= c[i];
	}

	// 시간 복잡도: O(N)
	// 각 동전에 대해 단 두 번의 연산(나눗셈과 모듈로)만 수행

	cout << res;

	return 0;
}
