#include <bits/stdc++.h>
using namespace std;

int N;
int stairs[305];

int res = -0x7f7f7f7f;

void DP() {

}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 계단 오르기

    // 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

    // 첫 번째 계단은 무조건 밟아야 한다
    // 연속된 세 계단은 밟을 수 없다
    // 한번에 한 칸 혹은 두 칸 올라갈 수 있다
    // 마지막 계단은 반든시 밟아야 한다

    cin >> N;
    stairs[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    // BFS? 이건 최단거리 문제가 아니기 때문에 패스

    // 재귀함수? (실패)
    // Recursive(0, 0);

    // DP

    // 1. 테이블 정의하기: Dp[i] = i번째 계단까지 올라섰을 때의 점수 합의 최댓값
    // 2. 점화식 찾기:
    // Dp[6] .. 방법이 없다. 따라서 테이블을 다르게 정의해야 한다

    // 1. 테이블 정의하기: Dp[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값

    DP();

    return 0;
}
