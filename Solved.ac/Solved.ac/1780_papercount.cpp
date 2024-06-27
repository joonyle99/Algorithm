#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2500][2500];
int cnt[3];

void Func(int ltx, int lty, int rbx, int rby)
{
    // bool값을 사용하지 않고 하려면, 따로 빼서 bool 값을 반환하는 함수로 만들 수 있다.
    bool isAllSame = true;

    // 종이 안에 모든 숫자가 같은지 확인한다
    int firstNumber = paper[ltx][lty];
    for (int i = ltx; i < rbx; i++) {
        for (int j = lty; j < rby; j++) {
            if (firstNumber != paper[i][j])
                isAllSame = false;
        }
    }

    // 종이 안의 모든 숫자가 같다면 해당 종이의 개수를 늘리고 반환 (더이상 쪼개지 않음)
    if (isAllSame) {
        cnt[firstNumber + 1]++;
        return;
    }

    // 더이상 쪼개지지 않는 베이스 컨디션
    if (rbx - ltx < 3 || rby - lty < 3) return;

    // 종이를 9등분 한다
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int ax = ltx + (rbx - ltx) / 3 * i;
            int ay = lty + (rby - lty) / 3 * j;
            int bx = ltx + (rbx - ltx) / 3 * (i + 1);
            int by = lty + (rby - lty) / 3 * (j + 1);
            Func(ax, ay, bx, by);
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 종이의 개수

    cin >> N;

    // paper
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> paper[row][col];
        }
    }

    Func(0, 0, N, N);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}
