#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 방 배정

    // N : 수학여행에 참가하는 학생 수를 나타내는 정수
    // K : 한 방에 배정할 수 있는 최대 인원 수
    // S : 성별
    // Y : 학년
    int N; int K;
    cin >> N >> K;

    // 2차원 배열을 이용한다
    int arr[7][2] = {};
    for (int i = 0; i < N; i++) {
        int S, Y;
        cin >> S >> Y;
        arr[Y][S]++;
    }

    int roomCount = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[i][j] == 0)
                continue;
           roomCount += arr[i][j] / K;
           if (arr[i][j] % K != 0)      // ** 추가로 더해주는 센스.. **
               roomCount++;
        }
    }

    cout << roomCount;

    return 0;
}
