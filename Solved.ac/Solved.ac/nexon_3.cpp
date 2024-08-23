#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a, b;

constexpr char odd[8] = { 'b', 'd', 'g', 'n', 'p', 'r', 's', 't' };
constexpr char even[5] = { 'a', 'e', 'i', 'o', 'u' };

// 시간 복잡도 O(1)의 삽입, 삭제, 탐색 (중복 허용 x)
unordered_set<string> candidates;

pair<int, int> GetStrikeBall(const string& s, const string& candidate) {
	int strike = 0, ball = 0;
	for (int i = 0; i < 4; ++i) {
		if (s[i] == candidate[i]) strike++;
		else if (candidate.find(s[i]) != string::npos) ball++;
	}
	return { strike, ball };
}

/// <summary>
/// 후보군 필터링 함수
/// 후보군을 정답이라고 '가정'한다면, 추측과 후보군의 결과가 일치해야 한다
/// 결과가 같다는 것은 '정답일 가능성이 있음'을 의미한다.
/// 반대로 결과가 다르다는 것은 '절대로 정답일 수 없음'을 의미한다.
/// </summary>
void Solution(const string& s, const int& a, const int& b) {
	for (auto iter = candidates.begin(); iter != candidates.end();) {
		const auto result = GetStrikeBall(s, *iter);
		if (result.first != a || result.second != b) iter = candidates.erase(iter);
		else ++iter;
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 공룡 이름 맞추기
	// 사실상 숫자 야구의 알파벳 버전

	// 이름의 1번째와 3번째는 서로 다른 'b', 'd', 'g', 'n', 'p', 'r', 's', 't'
	// 이름의 2번째와 4번째는 서로 다른 'a', 'e', 'i', 'o', 'u'

	/// [풀이 요령]
	/// n번의 추측 후에 정답이 O(1)로 구해져야 한다는 것이 포인트
	/// 결국 후보군을 이용한 필터링(소거법) 방식을 사용

	// 가능한 모든 공룡 이름 후보군을 확보
	candidates.reserve(8 * 7 * 5 * 4);	// 8P2 * 5P2
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i == j) continue;
			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 5; ++l) {
					if (k == l) continue;
					candidates.insert({ odd[i] , even[k] , odd[j] , even[l] });
				}
			}
		}
	}

	cin >> n;       // 질문 수

	while (n--) {
		cin >> s >> a >> b;
		Solution(s, a, b);
	}

	if (candidates.size() > 1) cout << 'x';
	else if (candidates.size() == 1) cout << *candidates.begin();
	else cout << 'x';

	return 0;
}
