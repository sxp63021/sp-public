#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#pragma once
class Serializer
{
public:
	struct MyStruct {
		int id;
		double value;
		string name;
	};

	static MyStruct mystruct_var;

	static bool serialize(const MyStruct&, const string&);
	static bool deserialize(MyStruct& data, const string& filename);


};

