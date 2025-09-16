#include <bits/stdc++.h>
using namespace std;

int n = 6;

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
    int move = 0;
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] % 2 != 0 && arr[right] % 2 == 0)
        {
            swap_ref(arr[left], arr[right]);
            move++;
            left++;
            right--;
        }
        else
        {
            // 짝수면 절대 안움직임
            if (arr[left] % 2 == 0)
            {
                left++;
            }
            
            if (arr[right] % 2 != 0)
            {
                right--;
            }
        }
    }

    return move;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 같은 팀끼리 모여라

    // Algorithm : 그리디 / 투 포인터

    int arr[] = { 1, 1, 1, 2, 2, 2 };

    print_value(arr);

    cout << Moves(arr) << '\n';

    print_value(arr);

    return 0;
}