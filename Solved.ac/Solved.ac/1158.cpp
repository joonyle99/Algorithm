#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 요세푸스 문제

    // 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고
    // 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다
    //
    // 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
    // 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다
    // 
    // 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열
    // 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
    //
    // N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성

    int N, K;
    cin >> N >> K;

    list<int> myList;
    for (int i = 1; i <= N; i++) {
        myList.push_back(i);
    }

    cout << '<';

    auto iter = myList.begin();
    while (!myList.empty()) {

        // 2칸 전진하기
        for (int i = 0; i < K - 1; i++) {
            iter++;
            if (iter == myList.end()) iter = myList.begin();
        }

        // K번째 번호 출력
        if (myList.size() == 1) cout << *iter;
        else cout << *iter << ", ";

        // K번째 번호 삭제
        iter = myList.erase(iter);
        if (iter == myList.end()) iter = myList.begin();
    }

    cout << '>';

    return 0;
}
