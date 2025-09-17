#include <bits/stdc++.h>
#include "Drawer.h"
using namespace std;

int n, d;
vector<int> weights;

int findMinWeight(vector<int> weights)
{
    for (int i = 0; i < d; i++)
    {
        int idx = max_element(weights.begin(), weights.end()) - weights.begin();
        weights[idx] -= floor(weights[idx] / 2);
    }

    int sum = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
    }

    return sum;
}

int findMinWeight2(vector<int> weights, int _d)
{
    priority_queue<int> maxPq; // 최대힙
                                // 전체 정렬을 하는게 아니라, 가장 앞에 우선순위가 가장 높은 것이 오는 것일 뿐
                                // 이게 우선순위 큐의 기능이다. 가장 우선순위가 높은 것 하나만 취급해야 하는 경우

    for (int i = 0; i < weights.size(); i++)
    {
        maxPq.push(weights[i]);
    }

    for (int i = 0; i < _d; i++)
    {
        int top = maxPq.top(); // 우선순위 큐에서 가장 우선순위 높은 것을 찾음 O(1)
        maxPq.pop();
        int eaten = top - floor(top / 2);
        maxPq.push(eaten); // 우선순위 큐에 원소를 추가함 O(logN) - 최대 힙(이진 트리)의 높이만큼의 연산이 필요함
    }

    int sum = 0;
    int pqSize = maxPq.size();
    for (int i = 0; i < pqSize; i++)
    {
        sum += maxPq.top();
        maxPq.pop();
    }

    return sum;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 최소한의 중량

    // Algorithm : 그리디 / 우선순위 큐

    /// 풀이 방법
    // 초콜릿 박스가 N개가 있고, 다양한 무게의 초콜릿이 들어있는데,
    // 가장 최소한의 중량을 만들기 위해서는, 가장 무거운 걸 먹어야한다 (1/2)
    // 따라서 주어진 기간(d) 동안 계속해서 무거운 초콜릿만 골라먹어야 하는데,
    // 처음에 시도한 vector에서 계속해서 찾는 방식은 O(N * D)로 O(N^2)의 시간복잡도
    // 따라서 우리는 가장 무게가 무거운 것만 골라내면 되므로, 우선순위 큐를 이용해서
    // 가장 무거운 초콜릿을 맨 앞에 위치하도록 한다.
    // 이렇게하면 먹은 초콜릿은 pop하고 무게가 줄어든 초콜릿을 다시 push하면
    // 가장 맨 앞에 존재하는(우선순위가 높은) 초콜릿을 O(1)에 접근할 수 있다 (초콜릿을 우선순위 적용하고 새롭게 추가하는 작업은 O(logN)

    cin >> n;
    cin >> d; // d가 200만까지 들어올 수 있으므로 O(N^2)은 택도 없다

    for (int i = 0; i < n; i++)
    {
        int input; cin >> input;
        weights.push_back(input);
    }

    cout << findMinWeight2(weights, d);

    return 0;
}
