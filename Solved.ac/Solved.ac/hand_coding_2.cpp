#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 중간에 만나는 두 연결 리스트의 시작점들이 주어졌을 때 만나는 지점을 구하기

    list<int> list1 = { 1,2,3,4,5,6,7,8,9,10 };
    for (const auto i : list1) cout << i << ' ';
    cout << '\n';
    cout << '\n';
    list<int> list2 = { 11,12,13,14,15 };
    for (const auto i : list2) cout << i << ' ';
    cout << '\n';
    cout << '\n';
    list<int> list3 = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
    for (const auto i : list3) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    auto iter = list3.begin();

    // 여기에서 list3와 만나도록 한다
    list1.push_back(*iter);
    list2.push_back(*iter);
    // 이건 그냥 값을 복사해서 넣는 것이기 때문에 연결되지 않는다

    for(const auto i : list1) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    for (const auto i : list2) cout << i << ' ';
    cout << '\n';
    cout << '\n';

    for (const auto i : list3) cout << i << ' ';
    cout << '\n';
    cout << '\n';
    return 0;
}
