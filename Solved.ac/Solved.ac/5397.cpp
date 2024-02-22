#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 키로거

	// 데이터의 삽입 삭제가 임의의 위치에서 발생한다
	// 연결 리스트를 사용한다

	int T; cin >> T;
	while (T--)
	{
		string input; cin >> input;
		int lenght = input.length();

		list<char> myList;
		auto iter = myList.end();	// 초기화된 상태 : iter == myList.begin() == myList.end()

		// 강산이가 백스페이스를 입력했다면, '-'가 주어진다.
		// 이때 커서의 바로 앞에 글자가 존재한다면, 그 글자를 지운다

		for (const auto c : input) {
			if (c == '<') {
				if (iter != myList.begin())
					iter--;
			}
			else if (c == '>') {
				if (iter != myList.end())
					iter++;
			}
			else if (c == '-') {
				if (iter != myList.begin()) iter = myList.erase(--iter);
			}
			else {
				myList.insert(iter, c);
			}

			/*
			* ~ Debug Code ~
			// 이 작업이 iterator의 상태를 보여주는 데 중요한 역할을 한다
			if (iter == myList.begin()) {
				cout << "iter is begin" << '\n';
			}
			else if (iter == myList.end()) {
				cout << "iter is end" << '\n';
			}
			else {
				cout << "iter value is " << *iter << '\n';
			}
			*/
		}

		for (const auto c : myList) {
			cout << c;
		}

		cout << '\n';
	}

	return 0;
}
