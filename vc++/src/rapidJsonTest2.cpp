// rapidJsonTest2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "rapidjson/document.h" 
#include "rapidjson/filewritestream.h" 
#include "rapidjson/writer.h" 
#include "rapidjson/stringbuffer.h"

#include <fstream> 
#include <iostream>

using namespace rapidjson;
using namespace std;

void toJson1(Document &oJson)
{
	oJson.SetObject();
	oJson.AddMember("id", rapidjson::Value(1), oJson.GetAllocator());
	const char* json1 = "{\"a\":1,\"b\":\"c\"}";
	Document d1(&oJson.GetAllocator());
	d1.Parse(json1);
	oJson.AddMember("test", d1, oJson.GetAllocator());
	return;
}

void toJson(Document &oJson)
{
	oJson.SetObject();
	oJson.AddMember("id", rapidjson::Value(1), oJson.GetAllocator());
	oJson.AddMember("version", "v1.0", oJson.GetAllocator());
//	Document d1(&oJson.GetAllocator());
//	toJson1(d1);

	//oJson.AddMember("test", d1, oJson.GetAllocator());
	return;
}


int main()
{
    std::cout << "Hello World!\n";

	Document d;

	toJson(d);

	StringBuffer buffer;
	Writer<StringBuffer> writer1(buffer);
	d.Accept(writer1);

	std::cout << buffer.GetString() << std::endl;
	
	// Approach 2, use serialize function and have the following
	// Link: https://github.com/Tencent/rapidjson/blob/master/example/simplewriter/simplewriter.cpp
	StringBuffer s;
	Writer<StringBuffer> writer(s);

	writer.StartObject();               // Between StartObject()/EndObject(), 
	writer.Key("hello");                // output a key,
	writer.String("world");             // follow by a value.
	writer.Key("t");
	writer.Bool(true);
	writer.Key("f");
	writer.Bool(false);
	writer.Key("n");
	writer.Null();
	writer.Key("i");
	writer.Uint(123);
	writer.Key("pi");
	writer.Double(3.1416);
	writer.Key("a");
	writer.StartArray();                // Between StartArray()/EndArray(),
	for (unsigned i = 0; i < 4; i++)
		writer.Uint(i);                 // all values are elements of the array.
	writer.EndArray();
	writer.EndObject();

	// {"hello":"world","t":true,"f":false,"n":null,"i":123,"pi":3.1416,"a":[0,1,2,3]}
	cout << s.GetString() << endl;
	return 0;
}

