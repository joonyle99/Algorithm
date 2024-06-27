#include <bits/stdc++.h>
using namespace std;
int N, M;
int cards[10];
int res[10];
void Func(int curCount) {
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = -1;
	for (int i = 0; i < N; i++) {
		if (temp == cards[i]) continue;
        // 7 1 / 9 1 / 9 7 과 같은 수열을 스킵한다
        if (curCount > 0) {
            if (cards[i] < res[curCount - 1])
                continue;
        }
		temp = cards[i];					/// ** 같은 깊이에서 이전 숫자와 중복되는 수를 넣으려고 하면 중복되는 수열이 만들어지기 때문에 X
		res[curCount] = cards[i];
		Func(curCount + 1);
	}
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N과 M (12)

    // 1. 고른 수열은 비내림차순이어야 한다.
    // => 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK - 1 ≤ AK를 만족하면, 비내림차순이라고 한다.

    // 2. 같은 수를 여러 번 골라도 된다.

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    std::sort(cards, cards + N);
    Func(0);

    return 0;
}
