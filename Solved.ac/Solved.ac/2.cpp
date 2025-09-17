#include <bits/stdc++.h>
using namespace std;

vector<int> nodeDistance(int s_nodes, int s_edges, vector<int> s_from, vector<int> s_to)
{
    // 순환하는 고리로부터의 거리를 배열로 반환
    // s_nodes의 각각의 거리를 반환함

    // 순환하는 노드를 찾는다


    //return
}

int main()
{
    // c와 c++의 stream을 끊습니다. (printf와 cout을 같이 혼용할 수 없습니다.)
    std::ios::sync_with_stdio(false);

    // cin으로 입력값을 받기 전에 cout버퍼를 비우지 않습니다.
    std::cin.tie(nullptr);

    // Title : 순환구조와의 거리를 구하시오

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
