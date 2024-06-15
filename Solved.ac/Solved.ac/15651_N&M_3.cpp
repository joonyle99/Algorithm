#include <bits/stdc++.h>
using namespace std;

int N, M;
int answerArray[10];

void Func(int curCount)
{
    if (curCount == M) {
        for (int i = 0; i < curCount; i++) {
            cout << answerArray[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int number = 1; number <= N; number++) {
        answerArray[curCount] = number;
        Func(curCount + 1);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N과 M (3)

    // 1. 1부터 N까지 자연수 중에서 M개를 고른 수열
    
    // 2. 같은 수를 여러 번 골라도 된다.

    // 3. 수열은 사전 순으로 증가하는 순서로 출력

    cin >> N >> M;

    Func(0);

    return 0;
}
