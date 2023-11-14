#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 번호 쌍을 어떠한 자료구조에 넣을 것인가?
std::vector<std::vector<int>> vec;

// 바이러스 걸린 컴퓨터
std::vector<int> virusComputer;

/// <summary>
/// DFS로 완전 탐색 해주는 함수
/// </summary>
/// <param name="n"></param>
void DFS(int n)
{
	// 들어온 값 n을 virusComputer에서 찾는다.
	auto it = std::find(virusComputer.begin(), virusComputer.end(), n);

	// 값이 있으면 종료
	if (it != virusComputer.end())
		return;
	// 값이 없으면 추가
	else
		virusComputer.push_back(n);

	// 들어오는 값에 들어가서 '깊이 우선 탐색'
	for (size_t i = 0; i < vec[n].size(); ++i)
	{
		DFS(vec[n][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 바이러스

	/*
	 * computerCount : 컴퓨터의 수
	 * network : 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수
	 */

	int computerCount; cin >> computerCount;
	int networkCount; cin >> networkCount;

	vec.resize(computerCount + 1);

	// 무방향 그래프
	for (int i = 0; i < networkCount; ++i)
	{
		int from; cin >> from;
		int to; cin >> to;

		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	// 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
	DFS(1);

	// 루트 컴퓨터 1번을 제외한 바이러스 걸린 수
	cout << virusComputer.size() - 1 << endl;


	return 0;
}