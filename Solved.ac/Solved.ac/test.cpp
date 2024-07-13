#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

#ifdef _DEBUG
	cout << "<디버그 모드>" << "\n\n";
#else
	cout << "<릴리즈 모드>" << "\n\n";
#endif

	int a = 10;
	int b = 20;

	std::cout << "변수 a의 주소: " << &a << '\n';
	std::cout << "변수 b의 주소: " << &b << "\n\n";

	// 주소 차이 계산
	ptrdiff_t diff = reinterpret_cast<char*>(&b) - reinterpret_cast<char*>(&a);

	std::cout << "두 변수 사이의 메모리 주소 차이: " << diff << " 바이트" << '\n';

	return 0;
}
