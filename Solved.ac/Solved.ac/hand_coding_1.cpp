#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 원형 연결 리스트 내의 임의의 노드 하나가 주어졌을 때,
    // 해당 List의 길이를 효율적으로 구하는 방법?

    // 자기 자신에서 시작에 자기 자신으로 돌아오는 길이를 구한다

    // 공간 복잡도 : O(1)
    // -> 자기 자신의 노드를 저장하는 변수 1개가 필요하기 때문이다

    // 시간 복잡도 ; O(N)
    // -> 원형 큐 내의 N개의 노드를 전부 돌면서 자기 자신을 발견할때 멈추기 때문이다

    return 0;
}
