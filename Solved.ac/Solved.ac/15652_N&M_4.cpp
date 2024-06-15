#include <bits/stdc++.h>
using namespace std;

int N, M;
int answerArray[10];

void Func(int curCount) {
    if (curCount == M) {
        for (int i = 0; i < curCount; i++) {
            cout << answerArray[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int startNumber = 1;
    // 등록된 요소의 개수가 1개 이상이라면, startNumber는 가장 최근에 등록되어있는 요소가 된다.
    if (curCount >= 1) startNumber = answerArray[curCount - 1];
    for (int number = startNumber; number <= N; number++) {
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

    // Title : N과 M (4)

    // 1. 1부터 N까지 자연수 중에서 M개를 고른 수열

    // 2. 같은 수를 여러 번 골라도 된다.

    // 3. 고른 수열은 비내림차순이어야 한다
    // => 오름차순에서 == 를 포함하는 경우

    cin >> N >> M;

    Func(0);

    return 0;
}
