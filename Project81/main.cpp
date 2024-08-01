#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "manager.h"
#include "user.h"

using namespace std;

#include "user.h"

enum loginState {
    isIng,isOK,pwErr
};


bool registUser(string id,string pw) {
    ofstream of;
	of.open("user_id.txt",ios::app);
    if (!of) {
        cout << "접근 실패로 인해 유저 등록 실패";
        return false;
    }
    of << id << ';' << pw << ':';
    cout <<"회원등록 성공 " << id << ' ' << pw << endl;
    of.close();
    return true;
}

void userAction(int isManager) {
    int mode;
	
	if (isManager == 1) {
		while(1) {
			cout<<"0. 추가, 1. 수정, 2. 삭제, 3. 조회"<<endl;
			Manager m;
			cin >> mode;
			cin.ignore();
			switch (mode) {
			case 0:
				cout << "추가"<<endl;
				m.registMember();
				break;
			case 1:
				cout << "수정"<<endl;
				m.modifyPw();
				break;
			case 2:
				cout << "삭제"<<endl;
				break;
			case 3:
				cout << "조회"<<endl;
				break;
			default:
				cout<<"종료"<<endl;
			}
   		}
	}
	else {
		User ur; //------------------------------
		while(1) {
			cout<<"0. 추가, 1. 수정, 2. 삭제, 3. 조회"<<endl;
			cin >> mode;
			switch (mode) {
			case 0:
				cout << "추가"<<endl;
				ur.addList();
				break;
			case 1:
				cout << "수정"<<endl;
				ur.modList();
				break;
			case 2:
				cout << "삭제"<<endl;
				ur.delList();
				break;
			case 3:
				cout << "조회"<<endl;
				ur.showList();
				break;
			default:
				cout<<"종료"<<endl;
			}
    	}
	}
    
    
}



int main()
{
    loginState ls;
    ifstream rf;
    ofstream of;

    while(1) {
        ls = isIng;
        rf.open("user_id.txt");

        if (!rf) {
            cout << "유저 정보 접근 실패";
            return -1;
        }

        string id,pw;
        cout << "********-초기 화면-********"<<endl;
        cout << "ID >> ";
        getline(cin,id);
        cout << "PW >> ";
        getline(cin,pw);
        cout << id << " " << pw << endl;

        int c;
        
        string str = "";

        while( (c=rf.get()) != EOF ) {
            if ((char)c == ':') {
				string cid="",cpw="";
                bool isID=true;
                for (char a: str) {
                    if (a == ';') {
                        isID = false;
                        continue;
                    }
                    if (isID) {
                        cid.append(1,a);
                    }
                    else {
                        cpw.append(1,a);
                    }
                }
                if (id == cid) {
                    ls = pwErr;
                    if (pw == cpw) {
                        ls = isOK;
                        break;
                    }
                }
                str = "";
            }
            else {
                str.append(1,(char)c);
            }
        }
        rf.close();
		//****----------------------------------------****//

        switch(ls) {
            case isIng:
            	//회원가입 진행
                cout << "회원가입" << endl;
                if (registUser(id, pw)) {
                    userAction(id == "admin" ? 1 : 0);
                }
                else {
                    // 유저 정보 오픈 실패
                    return -1;
                }
                break;
            case isOK:
				cout<<"로그인 성공"<<endl;
                userAction(id == "admin" ? 1:0);
                //로그인 성공
                break;
            case pwErr:
                // 아이디는 맞았는데 비밀번호가 틀림
                cout<<"비밀번호가 틀립니다 !!"<<endl;
                break;
            default:
                return -2;
            // 나오면 안되는 에러 상황
        }
    }
    return 0;
}
