#include "pch.h"
#include <memory>
#include <iostream>

using namespace std;

struct BodyMass
{
	int id; 
	float weight; 

	BodyMass(int id, float weight) :id(id), weight(weight)
	{
		cout << "BodyMass is constructed!" << endl;
		cout << "id = " << id << endl; 
		cout << "weight = " << weight << endl; 
	}
	BodyMass(const BodyMass &other) :id(other.id), weight(other.weight)
	{
		cout << "BodyMass is copy constructed!!" << endl; 
		cout << "id = " << id << endl;
		cout << "weight = " << weight << endl;
	}
	~BodyMass()
	{
		cout << "BodyMass is destructed!" << endl; 
	}
};

unique_ptr<BodyMass> GetBodyMass()
{
	return make_unique<BodyMass>(1, 51.8);
}

unique_ptr<BodyMass> UpdateBodyMass(unique_ptr<BodyMass> bodymass)
{
	bodymass->weight += 0.1;
	return bodymass;
}

auto main()->int
{
// 	cout << "unique_ptr_1" << endl;
// 	auto myWeight = make_unique<BodyMass>(1, 66.8);
// 	cout << endl << "Doing something!!!" << endl << endl; 
// 		
// 	auto copyWeight = *myWeight;

	auto myWeight = GetBodyMass();

	cout << "current weight" << myWeight->weight << endl; 
	myWeight = UpdateBodyMass(move(myWeight));				// move ; 데이터를 이동시키고자 할때는 std::move를 사용
	cout << "update weight" << myWeight->weight << endl; 

	return 0;
}