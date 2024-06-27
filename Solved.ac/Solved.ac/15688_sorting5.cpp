#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int freq[2 * MAX + 1];

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 수 정렬하기 5

    /// Counting Sort를 사용해서 문제를 해결할 수도 있다.

    // 비 내림차순이란?
    // 1 1 2 3 4 4 5 5 6 7 8 8 9 9 10

    // 1 <= N <= 1,000,000
    // -1,000,000 <= value <= 1,000,000

    // O(N)의 시간복잡도로 freq[]에 값을 추가한다
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int value; cin >> value;
        freq[value + MAX]++;        // 5를 입력받았으면, 1,000,000 + 5의 개수를 1증가
    }

    // O(K)의 시간복잡도로 K 범위의 수에 대한 출력을 실행한다
    for (int value = 0; value <= 2 * MAX; value++) {
        if (freq[value] == 0) continue;
        /*
        for (int count = 0; count < freq[value]; count++) {
            cout << value - MAX << '\n';
        }
        */
        while (freq[value]--) {
            cout << value - MAX << '\n';
        }
    }

    // O(N+K)의 시간복잡도를 가진 알고리즘
    // 즉, 수의 범위 (K) 가 작을수록 괴장히 효율적으로 동작하는 알고리즘이다.
    // 하지만 범위가 크면 사용할 수 없다. 메모리 문제로

    return 0;
}
