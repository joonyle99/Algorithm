#include <bits/stdc++.h>
using namespace std;

int n; // 수학 여행에 참가하는 학생 수
int k; // 한 방에 배정할 수 있는 최대 인원 수
int arr[7][2]; // row 학년, col 성별

int main() {
    for (int i = 1; i <=6; i++) {
        fill(arr[i], arr[i] + 2, 0);
    }
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        int y; cin >> y;
        arr[y][s]++;
    }
    int sum = 0;
    for (int y = 1; y <= 6; y++) {
        // k == 3
        // 
        // 0 -> 0
        // 
        // 1 -> 1
        // 2 -> 1
        // 3 -> 1
        // 
        // 4 -> 2
        // 5 -> 2
        // 6 -> 2
        // 
        // 7 -> 3
        // 
        // .
        // ..
        // ...

        // woman == 0
        // woman != 0
        // -> 

        // woman / k
        // 0
        // 0
        // 0
        // 1

        // woman / k + 1
        // 1
        // 1
        // 1
        // 2

        // (woman - 1) / k + 1
        // ?
        // 1
        // 1
        // 1
        // 2
        // 2

        // 여자
        int woman = arr[y][0];
        if (woman > 0) {

            sum += (woman - 1) / k + 1;
        }
        // 남자
        int man = arr[y][1];
        if (man > 0) {
            sum += (man - 1) / k + 1;
        }
    }
    cout << sum;
    return 0;
}