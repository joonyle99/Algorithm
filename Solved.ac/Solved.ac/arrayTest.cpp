#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len) {
	// 이 부분이 헷갈린다 ** 복습하자 **
	// out of range를 고려해서
	// ** 노트나 종이에 잘 구상을 해두고 구현하면 덜 헷갈릴 것이다 **
	// len vs len - 1
	// i > idx vs i >= idx
	// 오른쪽부터 밀어준다 (왼쪽부터 하면 임시 변수 생성해야 해서 추가 메모리 사용)
	// 당겨서 '가져온다'는 느낌으로 '보내준다'가 아니라
	for (int i = len; i > idx; --i) {
		arr[i] = arr[i - 1];
	}
	arr[idx] = num;
	len++;
}

void erase(int idx, int arr[], int& len) {
	// 이 부분이 헷갈린다 ** 복습하자 **
	// 왜 len부터 빼주는지를 생각하자
	// 왼쪽부터 당겨준다 (오른쪽부터 하면 임시 변수 생성해야 해서 추가 메모리 사용)
	// 당겨서 '가져온다'는 느낌으로 '보내준다'가 아니라
	len--;
	for (int i = idx; i < len; ++i) {
		arr[i] = arr[i + 1];
	}
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