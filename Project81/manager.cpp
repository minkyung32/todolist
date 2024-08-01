#include "manager.h"

void Manager::registMember() {
    cout << "New User Regist" << endl;
    cout << "Enter ID >> ";
    string id,pw;
    getline(cin,id);
    cout << "Enter PW >> ";
    getline(cin,pw);
    
    ofstream fout;
    fout.open("user_id.txt", ios::out | ios::app);
    // fout("user_id.txt", ios::out | ios::app);
    if (!fout) {
        cout << "File not Found" << endl;
        return;
    }
    fout << id << ';' << pw << ':';
    cout<<"회원 추가 성공"<<endl;
    fout.close();
}

void Manager::modifyPw() {
    ifstream fin;
    fin.open("user_id.txt");

    if (!fin) {
        cout << "유저 정보 접근 실패";
        exit(0);
    }
    cout<<"수정할 아이디를 입력하세요. >> ";
    string id,str="",cid="",cpw="";
    getline(cin,id);
    int c,fpos=-1;
    while( (c=fin.get()) != EOF ) {
        if ((char)c == ':') {
            bool isID=true;
            cid="",cpw="";
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
                fpos = fin.tellg();
                break;
            }
            str = "";
        }
        else {
            str.append(1,(char)c);
        }
    }
    fin.close();
    if (fpos == -1) {
        cout<<"수정할 아이디가 존재하지 않습니다."<<endl;
    }
    else {
        fstream f;
        f.open("user_id.txt",ios::in |ios::out);

        if (!f) {
            cout << "유저 정보 접근 실패";
            exit(0);
        }
        f.seekp(fpos-1);
        cout<<"변경할 비밀번호를 입력하세요. >> ";
        string pw,str="";
        getline(cin,pw);
        for (int i=0;i<cpw.length();i++)
            f << '\b';
    }


}
void deleteMember(ofstream& fout, string id) {

}
void searchMember(ofstream& fout, string id) {

}