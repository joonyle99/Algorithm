#include <bits/stdc++.h>
using namespace std;

vector<int> nodeDistance(int s_nodes, int s_edges, vector<int> s_from, vector<int> s_to)
{

    //return   
}

int main()
{
    // c�� c++�� stream�� �����ϴ�. (printf�� cout�� ���� ȥ���� �� �����ϴ�.)
    std::ios::sync_with_stdio(false);

    // cin���� �Է°��� �ޱ� ���� cout���۸� ����� �ʽ��ϴ�.
    std::cin.tie(nullptr);

    // Title : ��ȯ�������� �Ÿ��� ���Ͻÿ�

    // 

    ///

    int n_cnt; cin >> n_cnt;
    vector<int> from;

    for (int i = 0; i < n_cnt; i++)
    {
        int v; cin >> v;
        from.push_back(v);
    }

    int e_cnt; cin >> e_cnt;
    vector<int> to;

    for (int i = 0; i < e_cnt; i++)
    {
        int v; cin >> v;
        to.push_back(v);
    }

    vector<int> vec = nodeDistance(n_cnt, e_cnt, from, to);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}
