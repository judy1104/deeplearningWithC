#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main()->int
{
	vector<int> myvec;
	for (int i = 0; i < 10; ++i)
	{
		myvec.push_back(i);
	}

	cout << "ex1 ) " << endl; 
	for_each(begin(myvec), end(myvec), [](int n) {cout << n << " "; });
	cout << endl; 
	cout << endl;

	cout << "ex2 ) 람다 멀티라인" << endl;
	for_each(begin(myvec), end(myvec), [](int n)
	{
		cout << n << " is ";
		if(n < 2)
		{ 
			cout << "not" ; 
		}
		else
		{
			for (int i = 2; i < n; ++i)
			{
				if (n%i == 0)
				{
					cout << "not";
					break;
				}
			}
		}
		cout << "prime number" << endl; 
	});

	cout << endl;
	cout << endl;

	cout << "ex3 ) 람다 표현식에서 값 변환" << endl;
	vector<int> myvec2;
	myvec2.resize(myvec.size());
	transform(begin(myvec), end(myvec), begin(myvec2), [](int i) {return i * 3; });
	for_each(begin(myvec2), end(myvec2), [](int i) {cout << i << " "; });
	cout << endl;

	vector<double> myvec3;
	myvec3.resize(myvec2.size());
	transform(begin(myvec2), end(myvec2), begin(myvec3), [](int i)->double {return (i / 2.0); });
	for_each(begin(myvec3), end(myvec3), [](double d) {cout << d << " "; });

	cout << endl;
	cout << endl;

	cout << "ex4 ) 람다 표현식에서 값 캡쳐하기" << endl;	
	int a = 2; 
	int b = 7; 

	cout << "명시적으로 두 변수 캡쳐, a: " << a << ", b: " << b << endl;

	vector<vector<int>> veclist;
	veclist.push_back(myvec);
	veclist.push_back(myvec2);

	for_each(begin(veclist), end(veclist), [a, b](vector<int> vec) 
	{
		cout << "bewteen " << a << " and " << b << " : "; 
		for_each(begin(vec), end(vec), [a,b](int i) 
		{
			if (i >= a && i <= b)
			{
				cout << i << " ";
			}
		});	
		cout << endl; 
	});

	a = 3; 
	b = 5; 

	cout << "암시적으로 두 변수 캡쳐, a: " << a << ", b: " << b << endl;
	cout << "bewteen " << a << " and " << b << " : ";
	for_each(begin(myvec), end(myvec), [=](int i) 
	{
		if (i >= a && i <= b)
		{
			cout << i << " ";
		}
	});

	cout << "mutable 사용" << endl; 
	a = 1; 
	b = 1;

	for_each(begin(myvec), end(myvec), [=](int& x) 
	mutable{
		const int old = x; 
		x *= 2; 
		a = b; 
		b = old; 	
	});

	for_each(begin(myvec), end(myvec), [](int i) 
	{
		cout << i << " ";	
	});
	cout << endl; 

	cout << "a : " << a << ", b : " << b << endl; 

	return 0; 
}