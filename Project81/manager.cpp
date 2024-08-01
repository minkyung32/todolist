#include "manager.h"

void Manager::registMember(ofstream& fout) {
    cout << "New User Regist" << endl;
    cout << "Enter ID >> ";
    string id,pw;
    getline(cin,id);
    cout << "Enter PW >> ";
    getline(cin,pw);

    fout.open("user_id.txt", ios::out | ios::app);
    // fout("user_id.txt", ios::out | ios::app);
    if (!fout) {
        cout << "File not Found" << endl;
        return;
    }
    fout << id << ':' << pw << endl;
    cout<<"회원 추가 성공"<<endl;
    fout.close();
}

void Manager::modifyPw(ifstream& fin,ofstream& fout) {
    fin.open("user_id.txt");

    if (!fin) {
        cout << "유저 정보 접근 실패";
        exit(0);
    }
    cout<<"수정할 아이디를 입력하세요. >> ";
    string id,str="";
    getline(cin,id);
    int c;
    while( (c=fin.get()) != EOF ) {
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
                // 수정할 아이디가 있음
                cout<<"수정할 수 있음"<<endl;
                cout<<cid << " " << cpw<<endl;
                cout<<fin.tellg()<<endl;
            }
            str = "";
        }
        else {
            str.append(1,(char)c);
        }
    }
    cout<<"수정 종료"<<endl;
    fin.close();
}
void deleteMember(ofstream& fout, string id) {

}
void searchMember(ofstream& fout, string id) {

}