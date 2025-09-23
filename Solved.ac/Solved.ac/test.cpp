#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int sum_Y = 0;
    int sum_M = 0;
    for (int i = 0; i < n; i++) {
        int input; cin >> input;
        sum_Y += (input / 30 + 1) * 10;
        sum_M += (input / 60 + 1) * 15;
    }
    if (sum_Y > sum_M) {
        cout << "M " << sum_M;
    }
    else if (sum_Y < sum_M) {
        cout << "Y " << sum_Y;
    }
    else {
        cout << "Y M " << sum_Y;
    }
    return 0;
}