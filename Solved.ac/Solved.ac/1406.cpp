#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 에디터

	// 선형 자료구조에서 데이터를 삽입 / 삭제하려는 문제
	// N이 작으면 배열로도 해결이 가능하다
	// 하지만 삽입과 삭제가 빈번한 문제에서 배열보다는 연결 리스트로 해결해야 한다

	string input; cin >> input;

	// a -> b -> c -> d
	list<char> strList;
	for (const auto c : input) {
		strList.push_back(c);
	}

	// 커서는 제일 끝에 위치한다
	auto cursorIter = strList.end();

	int M; cin >> M;
	while (M--) {
		char instrument; cin >> instrument;
		switch (instrument) {
		case 'L':
			if (cursorIter != strList.begin())
				cursorIter--;
			break;

		case 'D':
			if (cursorIter != strList.end())
				cursorIter++;
			break;

		case 'B':
			if (cursorIter != strList.begin()) {
				cursorIter--;	// iterator erase (iterator p); 정확히 p에서 지우기 때문
				cursorIter = strList.erase(cursorIter);	// 그리고 p에서 지우면 p의 다음 요소를 가져온다 -> end()
			}
			break;

		case 'P':
			char character; cin >> character;
			strList.insert(cursorIter, character);
			break;
		}
	}

	// iterator based for
	for (const auto c : strList) {
		cout << c;
	}

	return 0;
}
