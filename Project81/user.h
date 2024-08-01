#pragma once
#include <iostream>
#include <string>

class User {
	string id;
	string pw;
	vector<string> list;
public:
	User() {}
	User(string id, string pw);
	~User();
	string getID();
	string getPW();
	void addUser(string id, string pw) {
		this->id = id;
		this->pw = pw;
	}
};