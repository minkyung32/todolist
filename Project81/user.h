#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class User {
	string id;
	string pw;
	vector<string> list;
	string addr;
public:
	User();
	User(string id, string pw);
	~User();
	string getID();
	string getPW();
	void addList();
	void modList();
	void delList();
	void showList();
	void fileIn();
	void fileOut();
};