#include "pch.h"
#include <iostream>
using namespace std;

auto main()->int
{
	cout << "for-loop.cpp" << endl; 

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };

	cout << "Display array using conventional for-loop " << endl;
	for (int i = 0; i < sizeof(arr); ++i)
	{
		cout << arr[i] << ", ";
	}
	cout <<  "count : "<< sizeof(arr) / sizeof(*arr) << endl;

	cout << "Display array using non-member begin() and end()" << endl;
	for(auto i = begin(arr); i != end(arr); ++i)
	{
		cout << *i << ", ";
	}
	cout << "count : " << sizeof(arr) / sizeof(*arr) << endl;
	cout << "*** 1) 주의: sizeof(arr) / sizeof(*arr), 배열 변수형으로 나눠줘야 배열 개수가 나옴" << endl; 
	cout << endl;

	cout << "Display array using range-based for loop" << endl; 
	for (auto a: arr)
	{
		cout << a << ", ";
	}
	
	return 0; 
}