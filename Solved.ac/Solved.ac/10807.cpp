#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 개수 세기

    int N; cin >> N; // 1 <= <= 100
    int arr[100] = {};
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // -100 <= <= 100
    }
    int v; cin >> v; // -100 <= <= 100
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == v) cnt++;
    }
    cout << cnt;
    return 0;
}