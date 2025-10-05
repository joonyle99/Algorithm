#include <bits/stdc++.h>
using namespace std;

int n; // 학생 수
int k; // 방의 정원
int arr[7][2]; // 각 학년별로 남/여가 얼마나 있는지를 담기 위한 변수 (첫 번째 행은 비워둔다)

int main() {
    for (int i = 1; i <= 6; i++) {
        fill(arr[i], arr[i] + 2, 0); // 0명으로 초기화
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int s, y;
        cin >> s >> y;
        arr[y][s]++;
    }
    int room = 0;
    for (int i = 1; i <= 6; i++) { // 학년
        for (int j = 0; j < 2; j++) { // 성별
            if (arr[i][j] != 0) {
                room += (arr[i][j] - 1) / k + 1; // 직접 계산식 하나하나 대입하며 만들기
            }
        }
    }
    cout << room;

    return 0;
}