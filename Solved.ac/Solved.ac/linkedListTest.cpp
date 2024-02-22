#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int datas[MAX], prePointer[MAX], nextPointer[MAX];
int newIndex = 1;

void insert(int frontAddress, int number) {
    datas[newIndex] = number;

    prePointer[newIndex] = frontAddress;
    nextPointer[newIndex] = nextPointer[frontAddress];

    if (nextPointer[frontAddress] != -1) {  // 전의 요소가 가리키던게 있다면
        prePointer[nextPointer[frontAddress]] = newIndex;
    }
    nextPointer[frontAddress] = newIndex;

    newIndex++;
}

void erase(int address) {
    //datas[address] = -1;
    
    nextPointer[prePointer[address]] = nextPointer[address];    // 이전 요소가 없을 수가 없다 (보장된다. Dummy Node 때문에)
    if (nextPointer[address] != -1) {
        prePointer[nextPointer[address]] = prePointer[address]; // 마지막 요소가 없을 경우를 대비
    }

    //prePointer[address] = -1;
    //nextPointer[address] = -1;
}

void traverse() {
    int current = nextPointer[0];
    while (current != -1) {
        cout << datas[current] << ' ';
        current = nextPointer[current];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)                 // '0번지' 뒤에 10을 추가한다
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(prePointer, prePointer + MAX, -1); 
    fill(nextPointer, nextPointer + MAX, -1);
    insert_test();
    erase_test();
}