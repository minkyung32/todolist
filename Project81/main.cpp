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


bool registUser(string id,string pw,ofstream& of) {
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

void userAction(ofstream& fout,ifstream& fin,string id) {
    int mode;
	if (id == "admin") {
	exit(0);

    User ur; //------------------------------

	if (isManager == 1) {
		while(1) {
			Manager m;
			cin >> mode;
			cin.ignore();
			switch (mode) {
			case 0:
				cout << "추가"<<endl;
				m.registMember(fout);
				break;
			case 1:
				cout << "수정";
				m.modifyPw(fin,fout);
				break;
			case 2:
				cout << "삭제";
				break;
			case 3:
				cout << "조회";
				break;
			default:
				cout<<"종료";
			}
   		}
	}
	else {
		while(1) {
		cin >> mode;
        switch (mode) {
        case 0:
            cout << "추가" << endl;
			// of.open(id.append(".txt"),ios::app);
			// if (!of) {
			// 	cout << "접근 실패로 인해 유저 등록 실패";
			// 	return;
			// }
			// of << "hello";
			// of.close();
            break;
        case 1:
            cout << "수정"<<endl;
            break;
        case 2:
            cout << "삭제"<<endl;
            break;
        case 3:
            cout << "조회"<<endl;
            cout << "추가";
            ur.addList();
            break;
        case 1:
            cout << "수정";
            ur.modList();
            break;
        case 2:
            cout << "삭제";
            ur.delList();
            break;
        case 3:
            cout << "조회";
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
		//****---------------------------------------- */

        switch(ls) {
            case isIng:
            //회원가입 진행
			cout<<"회원가입"<<endl;
            if ( registUser(id,pw,of) ) {
                userAction(of,rf,id);
            }
            else { 
                // 유저 정보 오픈 실패
                return -1;
            }
            break;
            case isOK:
				cout<<"로그인 성공"<<endl;
                userAction(of,rf,id);
            //로그인 성공
            break;
                //회원가입 진행
                cout << "회원가입" << endl;
                if (registUser(id, pw, of)) {
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
