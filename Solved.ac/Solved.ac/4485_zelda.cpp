#include <bits/stdc++.h>
using namespace std;

int N;

const int MAX_SIZE = 130;

int cave[MAX_SIZE][MAX_SIZE];
bool visited_J[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

void Dijkstra_Function()
{

}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 녹색 옷 입은 애가 젤다지?

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        // i = N (세로), j = N (가로)
        // 이렇게 하므로써, 전치행렬화 한다
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int k; cin >> k;
                cave[j][i] = k;
            }
        }

        // 최단 거리 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[j][i] = cave[j][i];
            }
        }

        // dijksta는 start 노드를 기점으로 모든 노드까지의 최단 거리를 구하는 알고리즘이다.
        // Dijkstra_Function(start);

        // [0, 0] -> [N-1, N-1]
        cout << "Problem " << N + 1 << ": " << dist[N - 1][N - 1] << '\n';
    }

    return 0;
}
