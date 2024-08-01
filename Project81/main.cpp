#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
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

void fileRead(vector<string>& v, ifstream& fin) {
	string line;
	string id, pw;
	while (getline(fin, line)) {
		int slash = line.find(':');
		id = line.substr(0, slash);
		pw = line.substr(slash + 1, line.length());

		v.push_back(id);
		v.push_back(pw);
	}
}
bool search(vector<string>& v, string key) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].compare(key);
		if (index == 0) { //found
			cout << "found" << endl;
			return 1;
		}
	}
	return 0;
}
int main() {
	vector<string> user_id;
//	vector<User> user;

//	class User ur;
	
	while (1) {
		ifstream fin("user_id.txt");
		if (!fin) {
			cout << "������ �� �� �����ϴ�." << endl;
		}
		fileRead(user_id, fin); //���� ���κ��� �б�
		fin.close();
		string id, pw;
		cout << "ID> ";
		getline(cin, id);
		if (id == "exit") break;
		cout << "PW> ";
		getline(cin, pw);

		if (search(user_id, id)) {
			if (search(user_id, pw)) {
				//id, pw ��ġ
				//"�α��� ����";

			//	ur.addUser(id, pw);
			//em.addEmployee(new FulltimeWorker("������", 10000, 300));
				//void EmployeeManager::addEmployee(Employee * emp) {
				//	empList.push_back(emp);
				//	//	empList[empNum] = emp;
				//	//	empNum++;
				//}


				while (1) {
					int sel;
					cout << "---To Do List---" << endl;
					cout << "1. �� �� �߰�" << endl;
					cout << "2. �� �� ����" << endl;
					cout << "3. �� �� ����" << endl;
					cout << "9. ����" << endl;
					cout << "----------------" << endl;
					cout << ">>";
					cin >> sel; getchar();
					if (sel == 1)
						cout << "�߰�" << endl;
					else if (sel == 2)
						cout << "����" << endl;
					else if (sel == 3)
						cout << "����" << endl;
					else if (sel == 9) break;
					else cout << "�߸��� �Է�" << endl;
				}
			}
			else
			{
				cout << "�н����尡 ��ġ���� �ʽ��ϴ�." << endl;
				continue;
			}
		}
		else {
			cout << "�ű� �������Դϴ�. �α��� �ϼ���." << endl;
			//vector �� push
			ofstream fout("user_id.txt", ios::out | ios::app);
			if (!fout) {
				cout << "���� ����" << endl;
				return 0;
			}
			fout << id << ':' << pw << endl;
			fout.close();
			continue;
		}
	}

}