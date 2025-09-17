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
    priority_queue<int> maxPq; // �ִ���
                                // ��ü ������ �ϴ°� �ƴ϶�, ���� �տ� �켱������ ���� ���� ���� ���� ���� ��
                                // �̰� �켱���� ť�� ����̴�. ���� �켱������ ���� �� �ϳ��� ����ؾ� �ϴ� ���

    for (int i = 0; i < weights.size(); i++)
    {
        maxPq.push(weights[i]);
    }

    for (int i = 0; i < _d; i++)
    {
        int top = maxPq.top(); // �켱���� ť���� ���� �켱���� ���� ���� ã�� O(1)
        maxPq.pop();
        int eaten = top - floor(top / 2);
        maxPq.push(eaten); // �켱���� ť�� ���Ҹ� �߰��� O(logN) - �ִ� ��(���� Ʈ��)�� ���̸�ŭ�� ������ �ʿ���
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

    // Title : �ּ����� �߷�

    // Algorithm : �׸��� / �켱���� ť

    /// Ǯ�� ���
    // ���ݸ� �ڽ��� N���� �ְ�, �پ��� ������ ���ݸ��� ����ִµ�,
    // ���� �ּ����� �߷��� ����� ���ؼ���, ���� ���ſ� �� �Ծ���Ѵ� (1/2)
    // ���� �־��� �Ⱓ(d) ���� ����ؼ� ���ſ� ���ݸ��� ���Ծ�� �ϴµ�,
    // ó���� �õ��� vector���� ����ؼ� ã�� ����� O(N * D)�� O(N^2)�� �ð����⵵
    // ���� �츮�� ���� ���԰� ���ſ� �͸� ��󳻸� �ǹǷ�, �켱���� ť�� �̿��ؼ�
    // ���� ���ſ� ���ݸ��� �� �տ� ��ġ�ϵ��� �Ѵ�.
    // �̷����ϸ� ���� ���ݸ��� pop�ϰ� ���԰� �پ�� ���ݸ��� �ٽ� push�ϸ�
    // ���� �� �տ� �����ϴ�(�켱������ ����) ���ݸ��� O(1)�� ������ �� �ִ� (���ݸ��� �켱���� �����ϰ� ���Ӱ� �߰��ϴ� �۾��� O(logN)

    cin >> n;
    cin >> d; // d�� 200������ ���� �� �����Ƿ� O(N^2)�� �õ� ����

    for (int i = 0; i < n; i++)
    {
        int input; cin >> input;
        weights.push_back(input);
    }

    cout << findMinWeight2(weights, d);

    return 0;
}
