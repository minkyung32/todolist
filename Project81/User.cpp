#include "user.h"

User::User() {

}
User::User(string id, string pw) {
	this->id = id;
	this->pw = pw;
}
User::~User() {

}
string User::getID() {
	return id;
}
string User::getPW() {
	return pw;
}
void User::addList() {
	cout << "******************" << endl;
	cout << "Have to do>> ";
	string todo;
	getline(cin, todo);
	list.push_back(todo);
	showList();
	fileOut();
}
void User::modList() {
	showList();
	cout << "******************" << endl;
	cout << "Number to modify>> ";
	int num;
	cin >> num; getchar();
	cout << ">> ";
	string mod;
	getline(cin, mod);
	list[num - 1] = mod;
	fileOut();
}
void User::delList() {
	showList();
	int num;
	cout << "******************" << endl;
	cout << "Number to delete>> ";
	cin >> num; getchar();
	vector<string>::iterator it;
	it = list.begin();
	int i = 0;
	it = it + (num - 1);
	list.erase(it);
	fileOut();

}
void User::showList() { //view, fileout
	fileIn();
	for (int i = 0; i < list.size(); i++)
		cout << i + 1 << ". " << list[i] << endl;
}
void User::fileIn() {
	addr = id + ".txt";
	ifstream fin(addr, ios::app);

	if (!fin) {
		cout << "file not found" << endl;
		exit(1);
	}
	else {
		string line;
		list.clear();
		while (getline(fin, line))
			list.push_back(line);
	}
	fin.close();
}
void User::fileOut() {
	ofstream fout(addr, ios::trunc);
	if (!fout) {
		cout << "File not Found" << endl;
		exit(1);
	}
	for (int i = 0; i < list.size(); i++)
		fout << list[i] << endl;
	fout.close();
}