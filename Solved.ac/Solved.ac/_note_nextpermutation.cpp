#include <iostream>
#include <algorithm>
using namespace std;

// std::next_permutation()
// 
// Permutes the range [first, last) into the next permutation
// Returns true if such a “next permutation” exists;
// otherwise transforms the range into the lexicographically first permutation (as if by std::sort) and returns false.
//
// 1. 배열의 가장 오른쪽에서 시작해서 왼쪽으로 이동하며 처음으로 왼쪽 원소가 오른쪽 원소보다 작은 '위치'를 i라고 한다.
// 2. 다시 배열의 가장 오른쪽에서 시작해서 i번째 '위치'의 원소보다 큰 첫 번째 원소를 j라고 한다.
// 3. i와 j 위치의 원소를 서로 교환합니다.
// 4. i 이후의 원소를 뒤집는다 (*** 여기서 i는 포함하지 않는다 ***)
//
// [1, 2, 3]에서 2와 3을 교환하면 [1, 3, 2]이 됩니다. (i = 1, j = 2)
// -> i 이후의 원소를 뒤집으면 [1, 3, 2]이 됩니다.
// 
// [1, 3, 2]에서 1과 2를 교환하면[2, 3, 1]이 됩니다. (i = 0, j = 2)
// -> i 이후의 원소를 뒤집으면 [2, 1, 3]이 됩니다.
// 
// [2, 1, 3]에서 1과 3을 교환하면[2, 3, 1]이 됩니다. (i = 1, j = 2)
// -> i 이후의 원소를 뒤집으면 [2, 3, 1]이 됩니다.
// 
// [2, 3, 1]에서 2와 3을 교환하면[3, 2, 1]이 됩니다. (i = 0, j = 1)
// -> i 이후의 원소를 뒤집으면 [3, 1, 2]이 됩니다.
// 
// [3, 1, 2]에서 1과 2를 교환하면[3, 2, 1]이 됩니다. (i = 1, j = 2)
// -> i 이후의 원소를 뒤집으면 [3, 2, 1]이 됩니다.

void Test_Permutation() {

	int a[3] = { 1,2,3 };

	// 3P3 ( 서로다른 3개의 원소 중, 순서를 고려하여 3개를 고르는 경우의 수 = 3! / 0! = 6 )
	do {	// do-while을 사용하는 이유는, 순열 함수를 돌리기 전에 초기 상태의 배열을 출력해야 하기 때문이다.

		/*
		* 
		* 배열을 다음과 같은 순서로 재배열 해준다
		* 
			(1) 1, 2, 3
			(2) 1, 3, 2
			(3) 2, 1, 3
			(4) 2, 3, 1
			(5) 3, 1, 2
			(6) 3, 2, 1
			-> (7) 1, 2, 3 만들고 False 반환
		*/

		for (int i = 0; i < 3; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	} while (std::next_permutation(std::begin(a), std::end(a)));
}

void Test_Permutation2() {
	int a[3] = { 1,2,3 };
	int cycleCount = 0;

	for (int i = 0; i < 20; i++) {
		// print elements
		for (int i = 0; i < 3; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';

		// next permutation & check cycle
		if (std::next_permutation(std::begin(a), std::end(a)) == false) {
			cycleCount++;
			cout << "===========> cycleCount: " << cycleCount << '\n';
		}
	}
}

void Test_Combination() {

	// *** 0의 위치는 내가 뽑고자 하는 원소의 위치를 나타낸다. ***
	int _b[4] = { 0, 0, 1, 1 };

	// 4C2 == 4! / (4-2)! * 2! = 4 x 3 / 2 = 6
	do {

		/*
			  <순열>

			0, 0, 1, 1
			0, 1, 0, 1
			0, 1, 1, 0
			1, 0, 0, 1
			1, 0, 1, 0
			1, 1, 0, 0
		*/

		for (int i = 0; i < 4; i++) {
			// 움직이는 0의 위치를 출력한다 (조합)
			if (_b[i] == 0) {
				// i는 배열의 인덱스이므로, i+1을 출력해야지 값이 1 ~ N인 배열의 조합을 출력할 수 있다.
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} while (std::next_permutation(std::begin(_b), std::end(_b)));
}

void Test_Combination2() {

	int c[5] = { 1,2,3,4,5 };
	int _c[5] = { 0, 0, 0, 1, 1 };

	// 5C3 == 5! / (5-3)! * 3! = 5 x 4 / 2 = 10
	do {

		/*
			 <순열>

		* 0, 0, 0, 1, 1
		* 0, 0, 1, 0, 1
		* 0, 0, 1, 1, 0
		* 0, 1, 0, 0, 1
		* 0, 1, 0, 1, 0
		* 0, 1, 1, 0, 0
		* 1, 0, 0, 0, 1
		* 1, 0, 0, 1, 0
		* 1, 0, 1, 0, 0
		* 1, 1, 0, 0, 0
		*/

		for (int i = 0; i < 5; i++) {
			if (_c[i] == 0) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} while (std::next_permutation(std::begin(_c), std::end(_c)));
}

void Test_Combination3() {

	// 이 배열에서 4개의 숫자를 뽑아 가능한 모든 조합을 출력하는 프로그램을 작성하세요.
	int numbers[6] = { 42, 17, 56, 23, 9, 34 };

	// 조건
	// 1. 출력되는 각 조합의 숫자는 오름차순이어야 합니다.
	// 2. 각 숫자는 배열 numbers에서 한 번만 뽑을 수 있습니다.
	// 3. 중복된 조합은 출력되지 않아야 합니다.

	// 예시 출력
	// 9 17 23 34
	// 9 17 23 42
	// 9 17 23 56
	// 9 17 34 42
	// 9 17 34 56
	// 9 17 42 56
	// 9 23 34 42
	// 9 23 34 56
	// 9 23 42 56
	// 9 34 42 56
	// 17 23 34 42
	// 17 23 34 56
	// 17 23 42 56
	// 17 34 42 56
	// 23 34 42 56

	// [9, 17, 23, 34, 42, 56]
	std::sort(numbers, numbers + 6);

	int _numbers[6] = { 0, 0, 0, 0, 1, 1 };

	do {
		for (int i = 0; i < 6; i++) {
			if (_numbers[i] == 0) {
				cout << numbers[i] << ' ';
			}
		}
		cout << '\n';
	} while (std::next_permutation(_numbers, _numbers + 6));
}

int main()
{
	// Test_Permutation();
	// 
	// cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << '\n';	// \u2501
	// 
	// Test_Permutation2();
	// 
	// cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << '\n';	// \u2501
	// 
	// Test_Combination();
	// 
	// cout << "────────────────────────────────────────────" << '\n';	// \u2500
	// 
	// Test_Combination2();
	// 
	// cout << "────────────────────────────────────────────" << '\n';	// \u2500

	Test_Combination3();

	return 0;
}