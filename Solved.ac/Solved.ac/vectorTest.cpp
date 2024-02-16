#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> v1(3, 5); // {5,5,5};
	cout << v1.size() << '\n'; // 3
	/// push_back()은 맨 마지막 인덱스에 값을 넣으므로 O(1)
	/// 추가로 push_front()는 O(N)이다
	v1.push_back(7); // {5,5,5,7};

	vector<int> v2(2); // {0,0};
	/// insert()는 당연하게도 O(N) (기본적으로 배열에서의 삽입)
	v2.insert(v2.begin() + 1, 3); // {0,3,0};

	vector<int> v3 = { 1,2,3,4 }; // {1,2,3,4}
	/// erase()도 당연하게 O(N) (기본적으로 배열에서의 삭제)
	v3.erase(v3.begin() + 2); // {1,2,4};

	vector<int> v4; // {}
	/// vector STL의 복사
	/// DeepCopy가 발생한다. O(N)
	v4 = v3; // {1,2,4}
	cout << v4[0] << v4[1] << v4[2] << '\n';
	/// pop_back()은 맨 마지막 인덱스의 값을 제거하는 것이므로 O(1)
	/// 추가로 pop_front()는 O(N)이다
	v4.pop_back(); // {1,2}
	/// clear()는 모든 요소(N)개를 돌면서 삭제하기 때문에 O(N)
	v4.clear(); // {}

	/// vector.size()에서 주의하고 넘어갈점
	vector<int> test;
	cout << '\n' << test.size() - 1 << '\n';
}