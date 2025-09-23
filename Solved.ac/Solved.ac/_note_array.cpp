// 배열은 '메모리 상'에 원소를 연속하게 배치한 자료구조
// 원래 C++에서는 '정적 배열'을 의미하지만 자료구조로써는 '동적 배열'을 상정한다
// 
// [배열의 성질]
// 1. O(1)에 K번째 원소에 임의 접근이 가능하다
// 2. 추가적으로 소모되는 메모리의 양이 거의 없음 (그냥 배열이라는 바구니를 만들고 안에 요소를 넣을 뿐)
// -> 이후 나올 자료구조에서는 바구니를 만들기 위해서 보조 바구니가 필요하거나 할 수 있음
// 3. 메모리 상에 연속해서 있기 때문에 Cache Hit Rate가 높다.
// 
// [시간 복잡도]
// 1. 배열 맨 뒤에 원소를 추가: O(1)
// 2. 배열 맨 뒤의 원소를 제거: O(1)
// 3. 배열의 K번째 인덱스의 원소를 확인 or 값 변경: O(1)
// 4. 배열의 K번째 인덱스에 원소를 추가 or 제거: O(N)
// 
// 예시)
// 0 | 1 | 2 | 3 | 4 | ...
// 2 | 4 | 6 | 14 | -1 | ...
//
// [배열은 두 가지 용도로 사용]
// 
// 1. 입력값을 담아두기 위한 용도
// -> 문제가 시작할 때 입력을 받는데, 그 값들을 담아두기 위한 용도
// --> e.g) int arr[26] = { 0, };
// --> int alphabet = (int)s[i] - 'a';
// --> arr[alphabet]++;
// 2. 빠르고 효율적인 O(1)로 접근하기 위한 용도
// -> 길이가 N인 배열 안에서 두 원소의 합이 100이되는 경우를 찾아야 할 때
// --> 길이가 N인 배열을 순회하면서 bool arr[101]에 (100 - input)의 원소가 true인지 확인
// --> 이 방식은 O(N)으로 배열을 순회하면서 해당 위치의 원소와 합해서 100이 되는 수를 찾는 과정을 O(1)에 알 수 있다
//
// 등장 횟수 저장 ex) int alphabet[26]; alphabet[c - 'a']++;
// 해당하는 숫자가 등장한 적이 있는지 확인 ex) checkArr[input] = 1; if(checkArr[x - input] == 1) {}

#include <algorithm>
#include <queue>
#include "Drawer.h"

using namespace std;

int main()
{
	// 배열 초기화 방법

	// 1. memset으로 초기화
	// -> 사용 안하는 거 추천 (번거롭고 실수 잦음)
	// 
	// 2. for문 직접 돌면서 초기화
	// -> 가장 직관적이고 무난한 방식임
	// 
	// 3. fill으로 초기화
	// -> 익숙해진다면 가장 추천하는 방식
	// -> 나는 이걸 사용할 것이다..!

	// fill
	// #include <algorithm>에 존재
	// void fill(ForwardIterator first, ForwardIterator last, const T& val);
	// -> last는 포함하지 않음..!

	int a[10];
	int b[10][10];

	Drawer::GetInstance().PrintArray(a, 10);
	fill(a, a + 5, -1);
	Drawer::GetInstance().PrintArray(a, 10);

	Drawer::GetInstance().PrintArray2(b, 10, 10);
	for (int i = 0; i < 10; i++) fill(b[i], b[i] + 5, -1);
	Drawer::GetInstance().PrintArray2(b, 10, 10);

	// 벡터 사용 시 주의 사항
	// -> c.size()는 unsigned int라서 0 ~ 2^32이라서
	// -> unsigned int overflow가 발생한다
	vector<int> c;
	auto temp = c.size() - 1;

	return 0;
}