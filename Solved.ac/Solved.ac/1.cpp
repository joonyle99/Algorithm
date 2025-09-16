#include <bits/stdc++.h>
using namespace std;

int n = 4;

void swap_ptr(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print_value(int arr[])
{
    cout << "[ ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }

    cout << " ]" << '\n';
}

/// <summary>
/// 
/// </summary>
/// <param name="arr">int arr[n]: 양의 정수 배열</param>
/// <returns>모든 짝수 요소가 홀수 요소보다 이전 인덱스에 있는 정수 배열을 정렬하는 데 필요한 최소 이동 횟수</returns>
int Moves(int arr[]) // int* arr와 같음
{
    // 모든 짝수 요소가 홀수 요소보다 앞에 있도록 정렬해야 하는데
    // 왼쪽부터 오른쪽으로 배열을 돈다
    // 홀수값이 있다면 last odd index를 저장한다
    // 이후에 짝수값이 나온다면 last odd index와 swap한다

    int last = -1;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            last = i;
            continue;
        }

        if (last != -1)
        {
            print_value(arr);
            
            swap_ptr(&arr[i], &arr[last]);

            print_value(arr);

            last = -1;
            cnt++;
        }

        //swap_ref(arr[i], arr[last]);
    }

    return cnt;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 같은 팀끼리 모여라

    int arr[] = { 8, 1, 4, 7 };

    cout << Moves(arr) << '\n';

    return 0;
}