#pragma once

#include <chrono>
#include <iostream>
#include <string>

class Timer
{
private:
	static Timer* Instance;

public:
	// 지연 초기화 방식
	inline static Timer& GetInstance() {
		if (Instance == nullptr)
			Instance = new Timer;
		return *Instance;
	}

private:
	std::chrono::steady_clock::time_point chrono_start;
	std::chrono::steady_clock::time_point chrono_end;
	std::chrono::duration<double> chrono_intervalTime;

public:
	inline Timer() : chrono_start{}, chrono_end{}, chrono_intervalTime{} {}
	inline Timer(const Timer& timer) = delete;
	inline Timer& operator = (const Timer& timer) = delete;
	inline ~Timer() { delete Instance; }

public:
	inline void Start_ChronoVersion() {
		chrono_start = std::chrono::high_resolution_clock::now();
	}
	inline void End_ChronoVersion(std::string inputText) {
		chrono_end = std::chrono::high_resolution_clock::now();

		chrono_intervalTime = std::chrono::duration<double>(chrono_end - chrono_start);
		std::cout << inputText << " : " << chrono_intervalTime.count() << " seconds" << std::endl;
	}
};
