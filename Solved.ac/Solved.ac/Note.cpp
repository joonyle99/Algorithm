#include <bits/stdc++.h>
using namespace std;

// '우선 순위 큐'

// Queue는 pop을 할 때 '가장 먼저 들어온 원소'가 나오는 자료구조
// 연결 리스트 기반으로 구현된 기준

// 1.원소의 추가
// - O(1)
// 2. 가장 먼저 들어온 원소의 확인
// - O(1)
// 3. 가장 먼저 들어온 원소의 제거
// - O(1)

// Priority Queue는 pop을 할 때 '우선순위가 가장 높은 원소'가 나오는 자료구조

// 1. 원소의 추가
// - O(logN)
// - 원소를 추가할 때, 최대로 현재 힙의 높이만 확인해보면 되기 때문에 logN이 된다
// 2. 우선순위가 가장 높은 원소의 확인
// - O(1)
// 3. 우선순위가 가장 높은 원소의 제거
// - O(logN)

// 힙(Heap)을 이용하기 때문에 빠른 수행 속도를 가지며, '이진 트리'의 모양을 가지고있음
// 이진 트리(Binary Tree)는 각 정점(Node)의 자식(Edge)이 '최대' 2개인 트리를 의미

// 최소 힙 / 최대 힙이 존재
// 1. 최소 힙
// - 부모가 자식보다 작아야 함
// - 루트에 있는 값이 가장 작은 값이 된다
// 2. 최대 힙
// - 부모가 자식보다 커야 함
// - 루트에 있는 값이 가장 큰 값이 된다

// ⚠️'이진 검색 트리'와 '힙'은 다르다. 이진 트리라는 공통점만 있을 뿐, 서로 다른 구조임

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    priority_queue<int> maxPq; // 최대 힙
    priority_queue<int, vector<int>, greater<int>> minPq; // 최소 힙

    return 0;
}
