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
	inline void PrintVector(std::vector<int>& vec) {
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