#include <bits/stdc++.h>
using namespace std;

class Star
{
public:
	int ID;
	unordered_set<Star*> Links;

public:
	Star(int _id) {
		this->ID = _id;
	}
};

int M, N;
int a, b;
int result = 0;

unordered_map<int, Star*> registered;
unordered_map<int, bool> globalVisited;

int DFS(int  id, int cnt) {
	Star* star = registered[id];
	for (const auto& linkedStar : star->Links) {
		if (globalVisited[linkedStar->ID]) continue;
		globalVisited[linkedStar->ID] = true;
		cnt += DFS(linkedStar->ID, 1);
	}
	return cnt;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 우주여행! 하이퍼웜홀!

	/// [풀이 요령]
	/// 
	/// ID의 최소값은 0, 최대값은 2147483647이기 때문에 배열의 인덱스로는 ID를 저장할 수 없다.
	/// 따라서 해시 테이블을 이용해 ID를 관리한다
	/// 
	/// 해당 문제에서는 별이 서로 이어져있는가?에 대해서 집중하므로, 순서는 고려하지 않아도 된다
	/// 따라서 메모리를 좀 사용하더라도 unordered_map, unordered_set 등 해시 테이블을 사용해 시간 복잡도 O(1)의 삽입, 검색을 실행한다
	/// 
	/// global visited를 사용해, 한 번 방문한 별은 재방문하지 않는다.
	/// 왜냐하면 a <----> b 와 같이 양방향 그래프임에도 '연결되어 있는지만' 알면 되기 때문이다.

	cin >> M;       // 하이퍼웜홀 개수
	cin >> N;       // 이동 가능한 별의 최소 개수

	registered.reserve(2 * M);

	for (int i = 0; i < M; ++i) {
		cin >> a >> b;		// 별의 ID 값

		// 등록되지 않은 별의 ID를 등록
		if (registered.count(a) == 0) {
			registered[a] = new Star(a);
			globalVisited[a] = false;
		}
		if (registered.count(b) == 0) {
			registered[b] = new Star(b);
			globalVisited[b] = false;
		}
		// a와 b사이의 웜홀을 연결
		registered[a]->Links.insert(registered[b]);
		registered[b]->Links.insert(registered[a]);
	}

	// 각 별에 대해 연결된 별들을 타고 들어가면서 연결된 별의 개수를 계산한다
	for (const auto& r : registered) {
		if (globalVisited[r.first]) continue;
		globalVisited[r.first] = true;
		int linkCount = DFS(r.first, 1);
		if (linkCount <= N) {
			result += linkCount;
		}
	}

	cout << result;

	return 0;
}

// 저장된 하이퍼웜홀의 정보를 확인하고
// a, b 중 저장된 적 있는 별이 있다면
// 해당 정보와 '병합'한다

// 경우 1. n번째 입력에서 1 ~ n번째 웜홀의 정보 중 a가 포함되어 있다면
// b를 해당 웜홀 정보에 이어 붙힌다 (그룹핑한다) => 혹은 병합을 택할 수도 있겠다

// 경우 2. n번째 입력에서 1 ~ n번째 웜홀의 정보 중 b가 포함되어 있다면
// a를 해당 웜홀 정보에 이어 붙힌다 (그룹핑한다) => 혹은 병합을 택할 수도 있겠다

// 경우 3. n번째 입력에서 1 ~ n번째 웜홀의 정보 중 a와 b가 동시에 포함되어 있다면
// (하나의 웜홀 정보에) 입력된 값을 처리하지 않고 스킵한다

// 경우 4. n번째 입력에서 1 ~ n번째 웜홀의 정보 중 a와 b가 서로 다른 (a는 k번째 b는 l번째)
// 웜홀 정보에 포함되어 있다면 k번째와 l번째 웜홀을 병합한다.

// 결과: 이로써 모든 웜홀의 정보들 중
// (입력받은 하이퍼웜홀의 개수는 M개 이지만, 실제로는 병합이 많이 이루어져 그보다 적거나 같은 것이다)
// 서로 겹치는 별의 ID가 없어질 것이다. (왜냐하면 겹치는 ID가 있을 때마다 병합을 해왔기 때문이다)
// 따라서 모든 웜홀의 정보들은 겹치지 않는 별의 ID들을 소유하고 있을 것이고, 이는 그룹핑이 완료되었음을 의미한다.


	/*
	for (const auto& r : registered) {
		cout << '[' << r.first << "] ===== > ";
		for (const auto& s : r.second->Links) {
			cout << s->ID << ' ';
		}
		cout << '\n';
	}
	*/