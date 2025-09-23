#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len) {
	// 임의의 인덱스에 원소를 추가
	// 배열의 길이를 한 칸 늘리는걸 어떻게 해야하지..?
	// 아 배열의 크기는 이미 넉넉하게 잡혀있어서 신경쓰지 않아도 되겠구나

	// idx의 위치에는 num이 들어가야 한다
	// 와.. 여기서 생각이 왜 안나지.. 머리로만 해서 그런가..?

	// len 인덱스부터 len - 1의 원소를 가져와 담는다
	// 그러면 결국에 idx 부분은 비어있게 되고, 나머지는 유지된다
	// O(N)의 시간복잡도를 가진다
	// 
	// TIP: 왼쪽 -> 오른쪽으로 옮겨가는게 아니라.
	// 오른쪽 -> 왼쪽으로 옮기면 추가 변수 없이도 가능하다
	//
	// CF: i > idx가 아닌 i >= idx로 작성했다면..?
	// idx에 idx - 1의 원소 값이 들어온 후 num으로 다시 덮으니까 상관 없지 않나 싶을 수 있는데
	// idx가 0인 경우 arr[0] = arr[-1]; 이 실행될 수 있어서 런타임 에러가 발생할 수 있다.
	for (int i = len; i > idx; --i) {
		arr[i] = arr[i - 1];
	}

	arr[idx] = num;
	len++;
}

void erase(int idx, int arr[], int& len) {
	// 임의의 인덱스의 원소를 제거

	// idx 인덱스부터 idx + 1의 원소를 가져와 담는다
	// 그러면 idx부터 그 이후의 모든 요소들이 앞당겨지게 된다
	// O(N)의 시간 복잡도를 가진다
	for (int i = idx; i < len - 1; ++i) {
		arr[i] = arr[idx];
	}

	// TODO: 위의 for문 안의 조건문 속에서 len - 1을 하는데,
	// for문 전에 len--;를 해주면 len - 1 대신 len을 사용할 수 있잖아
	// 좀 더 신중하게 생각을 해보자..! (우선은 이대로 코드를 남겨놔야지)
	len--;
}

void printArr(int arr[], int& len) {
	for (int i = 0; i < len; i++) cout << arr[i] << ' ';
	cout << "\n\n";
}

void insert_test() {
	cout << "***** insert_test *****\n";
	int arr[10] = { 10, 20, 30 };
	int len = 3;
	insert(3, 40, arr, len); // 10 20 30 40
	printArr(arr, len);
	insert(1, 50, arr, len); // 10 50 20 30 40
	printArr(arr, len);
	insert(0, 15, arr, len); // 15 10 50 20 30 40
	printArr(arr, len);
}

void erase_test() {
	cout << "***** erase_test *****\n";
	int arr[10] = { 10, 50, 40, 30, 70, 20 };
	int len = 6;
	erase(4, arr, len); // 10 50 40 30 20
	printArr(arr, len);
	erase(1, arr, len); // 10 40 30 20
	printArr(arr, len);
	erase(3, arr, len); // 10 40 30
	printArr(arr, len);
}

int main(void) {
	insert_test();
	erase_test();
}