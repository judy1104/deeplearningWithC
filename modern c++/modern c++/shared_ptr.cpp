#include "pch.h"
#include <memory>
#include <iostream>

using namespace std;

void IsInitialized(int id, shared_ptr<int>&sp)
{
	if (sp)
	{
		cout << "sp" << id << "is initialized" << endl<< endl;
	}
	else
	{
		cout << "sp" << id << "is not unique" << endl << endl;
	}
}

void IsUnique(int id, shared_ptr<int>&sp)
{
	if (sp.unique())
	{
		cout << "sp"<< id << "is unique" << endl << endl;
	}
	else
	{
		cout << "sp" << id << "is not unique" << endl << endl;
	}
}
auto main()->int
{
	cout << "shared_ptr" << endl;

	auto sp1 = shared_ptr<int>{};
	IsInitialized(1, sp1);

	cout << "sp1 pointing counter = " << sp1.use_count() << endl;

	IsUnique(1, sp1);

	sp1 = make_shared<int>(1234);
	IsInitialized(1, sp1);

	cout << "sp1 pointing counter = " << sp1.use_count() << endl;
	IsUnique(1, sp1);

	auto sp2 = sp1;
	cout << "sp1 pointing counter = " << sp1.use_count() << endl;
	IsUnique(1, sp1);

	cout << "sp2 pointing counter = " << sp2.use_count() << endl;
	IsUnique(2, sp2);

	sp2.reset();
	IsUnique(1, sp1);

	return 0;
}
// 
// auto main()->int
// {
// 	cout << "shared_ptr" << endl;
// 
// 	auto sp1 = shared_ptr<int>{};
// 	
// 	if (sp1)
// 	{
// 		cout << "sp1 is initialized" << endl;
// 	}
// 	else
// 	{
// 		cout << "sp1 is not initialized" << endl;
// 	}
// 	cout << "sp1 pointing counter = " << sp1.use_count() << endl; 
// 
// 	if (sp1.unique())
// 	{
// 		cout << "sp1 is unique" << endl << endl;
// 	}
// 	else
// 	{
// 		cout << "sp1 is not unique" << endl << endl;
// 	}
// 
// 	sp1 = make_shared<int>(1234);
// 	if (sp1)
// 	{
// 		cout << "sp1 is initialized" << endl;
// 	}
// 	else
// 	{
// 		cout << "sp1 is not initialized" << endl;
// 	}
// 	cout << "sp1 pointing counter = " << sp1.use_count() << endl;
// 	if (sp1.unique())
// 	{
// 		cout << "sp1 is unique" << endl << endl;
// 	}
// 	else
// 	{
// 		cout << "sp1 is not unique" << endl << endl;
// 	}
// 
// 	auto sp2 = sp1;
// 	cout << "sp1 pointing counter = " << sp1.use_count() << endl;
// 	if (sp1.unique())
// 	{
// 		cout << "sp1 is unique" << endl << endl;
// 	}
// 	else
// 	{
// 		cout << "sp1 is not unique" << endl << endl;
// 	}
// 
// 	cout << "sp2 pointing counter = " << sp2.use_count() << endl;
// 	if (sp2.unique())
// 	{
// 		cout << "sp2 is unique" << endl << endl;
// 	}
// 	else
// 	{
// 		cout << "sp2 is not unique" << endl << endl;
// 	}
// 
// 	sp2.reset();
// 	if (sp1.unique())
// 	{
// 		cout << "sp1 is unique" << endl << endl;
// 	}
// 	else
// 	{
// 		cout << "sp1 is not unique" << endl << endl;
// 	}
// 
// 	return 0;
// }