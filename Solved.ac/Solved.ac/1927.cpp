#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int n;
vector<int> vec;
priority_queue<int, vector<int>, Compare> pq;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 최소 힙

    // 가장 낮은 값을 출력하고 빼고.. 해야하니까
    // 우선순위큐를 사용한다

    cin >> n;
    while (n--) {
        int x; cin >> x;
        if (x > 0) {
            pq.push(x);
        }
        else if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
