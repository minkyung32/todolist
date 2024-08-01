#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#include "user.h"

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
			cout << "File not Found" << endl;
		}
		fileRead(user_id, fin); //파일 라인별로 읽기
		fin.close();
		string id, pw;
		cout << "ID> ";
		getline(cin, id);
		if (id == "exit") break;
		cout << "PW> ";
		getline(cin, pw);

		if (search(user_id, id)) {
			if (search(user_id, pw)) {
				//id, pw correct

			//	ur.addUser(id, pw);
			//em.addEmployee(new FulltimeWorker("이제훈", 10000, 300));
				//void EmployeeManager::addEmployee(Employee * emp) {
				//	empList.push_back(emp);
				//	//	empList[empNum] = emp;
				//	//	empNum++;
				//}


				while (1) {
					int sel;
					cout << "---To Do List---" << endl;
					cout << "1. add" << endl;
					cout << "2. modify" << endl;
					cout << "3. delete" << endl;
					cout << "9. exit" << endl;
					cout << "----------------" << endl;
					cout << ">>";
					cin >> sel; getchar();
					if (sel == 1)
						cout << "add" << endl;
					else if (sel == 2)
						cout << "mod" << endl;
					else if (sel == 3)
						cout << "delete" << endl;
					else if (sel == 9) break;
					else cout << "wrong" << endl;
				}
			}
			else
			{
				cout << "password is not correct" << endl;
				continue;
			}
		}
		else {
			cout << "New User. Login again" << endl;
			//vector 에 push
			ofstream fout("user_id.txt", ios::out | ios::app);
			if (!fout) {
				cout << "File not Found" << endl;
				return 0;
			}
			fout << id << ':' << pw << endl;
			fout.close();
			continue;
		}
	}

}