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
/// <param name="arr">int arr[n]: ���� ���� �迭</param>
/// <returns>��� ¦�� ��Ұ� Ȧ�� ��Һ��� ���� �ε����� �ִ� ���� �迭�� �����ϴ� �� �ʿ��� �ּ� �̵� Ƚ��</returns>
int Moves(int arr[]) // int* arr�� ����
{
    // ��� ¦�� ��Ұ� Ȧ�� ��Һ��� �տ� �ֵ��� �����ؾ� �ϴµ�
    // ���ʺ��� ���������� �迭�� ����
    // Ȧ������ �ִٸ� last odd index�� �����Ѵ�
    // ���Ŀ� ¦������ ���´ٸ� last odd index�� swap�Ѵ�

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

    // Title : ���� ������ �𿩶�

    int arr[] = { 8, 1, 4, 7 };

    cout << Moves(arr) << '\n';

    return 0;
}