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

int findMinWeight2(vector<int> weights)
{


    return 0;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 최소한의 중량

    // Algorithm : 그리디 / 우선순위 큐

    cin >> n;
    cin >> d;

    for (int i = 0; i < n; i++)
    {
        int input; cin >> input;
        weights.push_back(input);
    }

    cout << findMinWeight2(weights);

    return 0;
}
