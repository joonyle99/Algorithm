#include <bits/stdc++.h>
using namespace std;

int length;
int box[100000];        // length는 최대 100000개
int target;
int sequence[2000001];  // target는 최대 1000000

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 두 수의 합

    cin >> length;
    for (int index = 0; index < length; ++index) {
        cin >> box[index];
    }
    cin >> target;

    int cnt = 0;

    /*
    // O(N^2)
    // n : 100000인데
    // O(N^2)에서 이미 100억이 넘어감
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (box[i] + box[j] == x)
                cnt++;
        }
    }
    */

    // x = ai + aj

    // O(N)
    /// Baaaarking Dog 예제로 푼거랑 같은 문제
    /// 진짜 신기하다.. 알고리즘의 세계란..
    for (int index = 0; index < length; ++index) {
        int opposite = target - box[index];
        if (opposite < 0)   // index가 음수가 나오는 경우 예외처리
            continue;
        if (sequence[opposite] == 1)
            cnt++;
        else
            sequence[box[index]] = 1;
    }

    cout << cnt;

    return 0;
}
