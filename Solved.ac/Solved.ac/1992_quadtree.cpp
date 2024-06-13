#include <bits/stdc++.h>
using namespace std;

string board[65];

bool CheckAllSame(int ltr, int ltc, int length)
{
    int n = board[ltr][ltc];
    for (int row = ltr; row < ltr + length; row++) {
        for (int col = ltc; col < ltc + length; col++) {
            if (n != board[row][col])
                return false;
        }
    }

    return true;
}

void Func1(int ltr, int ltc, int length)
{
    // 모든 숫자가 같은지 체크한다
    if (CheckAllSame(ltr, ltc, length)) {
        // 같으면 해당 숫자를 출력한다
        cout << board[ltr][ltc];
        return;
    }

    cout << '(';

    // 쿼드 트리로 쪼갠다
    int half = length / 2;
    Func1(ltr + half * 0, ltc + half * 0, half);
    Func1(ltr + half * 0, ltc + half * 1, half);
    Func1(ltr + half * 1, ltc + half * 0, half);
    Func1(ltr + half * 1, ltc + half * 1, half);

    cout << ')';
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 쿼드 트리

    int N; cin >> N;
    for (int row = 0; row < N; row++) {
        cin >> board[row];
    }

    Func1(0, 0, N);

    return 0;
}
