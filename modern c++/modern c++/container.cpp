#include "pch.h"
#include <iostream>
#include <array>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
	return (a > b);
}

auto main()->int
{
	cout << "container-array, page 37" << endl; 
	array<int, 10> arr = { 0,1,2,3,4,5,6,7,8,9 };

	cout << "Original Data : ";
	for (auto i : arr)
		cout << i << ", ";
	cout << endl; 

	arr[1] = 85;
	arr[8] = 77;

	cout << "New Data :\t";
	for (auto i : arr)
		cout << i << ", ";
	cout << endl;
	cout << endl; 

	cout << "container-vector_sort, page 40" << endl;
	cout << "Original Data : ";
	vector<int> myVec = { 2,13,1,84,5,0 };
	for (auto v : myVec) cout << v << ", ";
	cout << endl;

	sort(myVec.begin(), myVec.end());

	cout << "after sort :\t";
	for (auto i : myVec) cout << i << ", ";
	cout << endl;

	sort(myVec.begin(), myVec.end(), compare);
	cout << "after Dsort :\t";
	for (auto i : myVec) cout << i << ", ";
	cout << endl;
	cout << "*** point 1) 내림차순 정렬 시, sort(myVec.begin(), myVec.end(), compare) 3번자 인자에 compare 함수를 만들어서 넣어줬다. " << endl;

	return 0; 
}