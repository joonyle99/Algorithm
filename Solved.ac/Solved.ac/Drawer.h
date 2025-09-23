#pragma once

#include <iostream>
#include <vector>

class Drawer
{
private:
    static Drawer* Instance;

public:
    // 지연 초기화 방식
    inline static Drawer& GetInstance() {
        if (Instance == nullptr)
            Instance = new Drawer;
        return *Instance;
    }

public:
	inline void PrintArray(int arr[], int len) {
        std::cout << "============= PrintArray =============" << '\n';

        std::cout << "[ ";

        for (int i = 0; i < len; i++)
        {
            if (i == len - 1)
            {
                std::cout << arr[i];
            }
            else
            {
                std::cout << arr[i] << ", ";
            }
        }

        std::cout << " ]" << '\n';
	}
    inline void PrintArray2(int arr[][10], int row, int col) {
        std::cout << "============= PrintArray2 =============" << '\n';

        for (int i = 0; i < row; i++) {

            std::cout << "[ ";

            for (int j = 0; j < col; j++)
            {
                if (j == col - 1)
                {
                    std::cout << arr[i][j];
                }
                else
                {
                    std::cout << arr[i][j] << ", ";
                }
            }

            std::cout << " ]" << '\n';
        }
    }
    inline void PrintVector(std::vector<int>& vec) {
        std::cout << "============= PrintVector =============" << '\n';

        std::cout << "[ ";

        for (int i = 0; i < vec.size(); i++)
        {
            if (i == vec.size() - 1)
            {
                std::cout << vec[i];
            }
            else
            {
                std::cout << vec[i] << ", ";
            }
        }

        std::cout << " ]" << '\n';
    }
};