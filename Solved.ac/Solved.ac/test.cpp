#include <bits/stdc++.h>
using namespace std;

int n;
int vArr[100000] = { 0, };
bool existArr[1000001] = { false, };
int x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> vArr[i]; // 입력값 저장용
        existArr[vArr[i]] = true; // 입력값 존재 여부 저장
    }
    cin >> x;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int vOrigin = vArr[i];
        if (x <= vOrigin) continue; // 합이 요소 하나보다 작거나 같으면 성립이 불가능 (입력값은 무조건 자연수)
        int vOpposite = x - vOrigin;
        if (vOpposite > 1000000) continue; // x는 200백만일 수 있는데 이 예외처리 안해주려면 existArr의 크기를 200백만으로 늘려주는 방법도 있음
        if (existArr[vOpposite] == true) {
            cnt++;
        }
    }
    cout << cnt / 2;
    return 0;
}