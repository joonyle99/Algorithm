#include <bits/stdc++.h>
using namespace std;

int main(void) {
    list<int> myList = { 1,2 }; // 초기화 리스트 (lnitial list) -> 1 2

    list<int>::iterator iter = myList.begin(); // iter는 1을 가리킨다

    // 가장 마지막 요소 or 가장 처음 요소에 데이터를 삽입하는 것은 해당 원소를 찾으러 가는 과정에서
    // 다른 원소를 타고갈 필요가 없으므로 O(1)의 시간복잡도로 데이터 삽입이 가능하다
    myList.push_front(10); // 10 1 2
    cout << *iter << '\n'; // iter가 가리키는 값 = 1을 출력 (이미 가리키고 있었음)
    myList.push_back(5); // 10 1 2 5
    myList.insert(iter, 6); // iter가 가리키는 곳 '앞에' 6을 삽입, 10 6 1 2 5

    // operator ++이 가능한 이유는 연결 리스트가 선형 자료구조이기 때문이다
    iter++; // iter를 1칸 앞으로 전진, 현재 iter가 가리키는 값은 2

    // iter가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
    iter = myList.erase(iter); // 10 6 1 5, iter가 가리키는 값은 5
    cout << *iter << '\n'; // 5

    // c++ 11 later : range based loop
    for (auto i : myList) cout << i << ' ';

    cout << '\n';

    // c++ 11 earlier : primitive loop
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
        cout << *it << ' ';
}