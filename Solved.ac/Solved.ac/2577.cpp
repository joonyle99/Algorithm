#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int boxArray[10];   // 전역변수 자동 초기화

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 숫자의 개수

    cin >> A >> B >> C;

    int mul = A * B * C;
    while (mul != 0) {
        boxArray[mul % 10]++;
        mul /= 10;
    }

    for (const auto v : boxArray)
        cout << v << '\n';

    return 0;
}
