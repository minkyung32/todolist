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
			cout << "파일을 열 수 없습니다." << endl;
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
				//id, pw 일치
				//"로그인 성공";

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
					cout << "1. 할 일 추가" << endl;
					cout << "2. 할 일 수정" << endl;
					cout << "3. 할 일 삭제" << endl;
					cout << "9. 종료" << endl;
					cout << "----------------" << endl;
					cout << ">>";
					cin >> sel; getchar();
					if (sel == 1)
						cout << "추가" << endl;
					else if (sel == 2)
						cout << "수정" << endl;
					else if (sel == 3)
						cout << "삭제" << endl;
					else if (sel == 9) break;
					else cout << "잘못된 입력" << endl;
				}
			}
			else
			{
				cout << "패스워드가 일치하지 않습니다." << endl;
				continue;
			}
		}
		else {
			cout << "신규 가입자입니다. 로그인 하세요." << endl;
			//vector 에 push
			ofstream fout("user_id.txt", ios::out | ios::app);
			if (!fout) {
				cout << "열기 실패" << endl;
				return 0;
			}
			fout << id << ':' << pw << endl;
			fout.close();
			continue;
		}
	}

}