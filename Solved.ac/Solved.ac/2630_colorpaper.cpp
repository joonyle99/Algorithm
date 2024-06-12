#include <bits/stdc++.h>
using namespace std;

int N; // 한 변의 길이
bool paper[130][130];
int paperCount[2];

bool CheckAllSame(int ltr, int ltc, int length)
{
    int firstNumber = paper[ltr][ltc];
    for (int row = ltr; row < ltr + length; row++) {
        for (int col = ltc; col < ltc + length; col++) {
            if (firstNumber != paper[row][col]) return false;
        }
    }

    return true;
}

void Func(int ltr, int ltc, int length) {

    // 모두 같은 색으로 칠해져 있는지 확인한다.
    if (CheckAllSame(ltr, ltc, length))
    {
        int paperNumber = paper[ltr][ltc];
        paperCount[paperNumber]++;
        return;
    }

    // 등분할 수 있는지 체크한다 (base condition)
    if (length < 2) return;

    // 4등분 한다
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            Func(ltr + length / 2 * row, ltc + length / 2 * col, length / 2);
        }
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 색종이 만들기

    // 전체 종이가 모두 같은 색으로 칠해져 있지 않으면
    // 가로와 세로로 중간 부분을 잘라서

    // 모두 하얀색 또는 모두 파란색으로 칠해져 있거나,
    // 하나의 정사각형 칸이 되어 더 이상 자를 수 없을 때까지 반복

    // 하얀색으로 칠해진 칸은 0
    // 파란색으로 칠해진 칸은 1

    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> paper[row][col];
        }
    }

    Func(0, 0, N);

    std::cout << paperCount[0] << '\n';
    std::cout << paperCount[1] << '\n';

    return 0;
}
