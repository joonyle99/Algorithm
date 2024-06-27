#include <bits/stdc++.h>
using namespace std;

int N, M;
int cards[10];
int res[10];

void Func(int curCount)
{
    if (curCount == M) {
        for (int i = 0; i < curCount; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        // 고른 수열은 비내림차순
        // 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

        int n = cards[i];

        if (curCount > 0) {
            // 이전 요소가 더 크다면 continue
            if (res[curCount - 1] > n)
                continue;
        }

        res[curCount] = n;
        Func(curCount + 1);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N과 M (8)

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    std::sort(cards, cards + N);

    Func(0);

    return 0;
}
