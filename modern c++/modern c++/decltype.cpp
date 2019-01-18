// modern c++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j)
{
	return i + j;
}

auto main() -> int
{
	cout << "auto and decltype" << endl; 

	auto d = add<int, double>(2, 3.14);

	cout << "add 2, 3.14 : " << d << endl; 

}
