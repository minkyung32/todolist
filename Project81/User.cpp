#include "user.h"

User::User() {
	fileIn();
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
	cout << "Have to do>> ";
	string todo;
	getline(cin, todo);
	list.push_back(todo);
	showList();
	//fout
}
void User::modList() {
	showList();
	cout << "Number to modify>> ";
	int num;
	cin >> num;
	cout << ">> ";
	string mod;
	getline(cin, mod);
	list[num + 1] = mod;
}
void User::delList() {
	showList();
	int num;
	cout << "Number to delete>> ";
	cin >> num;
	vector<string>::iterator it;
	int i = 0;
	while (i < num) {
		it++;
		i++;
	}
	it = list.erase(it);
}
void User::showList() { //view, fileout
	for (int i = 0; i < list.size(); i++)
		cout << i + 1 << ". " << list[i] << endl;
	//(�ε���+1)������ ���
	//�ε����� 2�� 3. ~~~ �� ��µ�
}
void User::fileIn() { //�α��� �� ȣ��
	addr = id + ".txt";
	ifstream fin(addr, ios::app);

	if (!fin) {
		cout << "file not found" << endl;
		exit(1);
	}
	else {
		string line;
		while (getline(fin, line))
			list.push_back(line);
	}
	fin.close();
}
void User::fileOut() { //�α׾ƿ��Ҷ����� ȣ��
	ofstream fout(addr, ios::trunc); //�����
	if (!fout) {
		cout << "File not Found" << endl;
		exit(1);
	}
	for (int i = 0; i < list.size(); i++)
		fout << list[i] << endl;
	fout.close();
}