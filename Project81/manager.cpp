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
    string id,str="",str2="",cid="",cpw="";
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
        ifstream fin;
        fin.open("user_id.txt");

        if (!fin) {
            cout << "유저 정보 접근 실패";
            exit(0);
        }
        cout<<"변경할 비밀번호를 입력하세요. >> ";
        string pw,str="";
        getline(cin,pw);
        fin.seekg(0,ios::beg);
        str = "";
        
        for (int i=0;i<fpos-(cpw.length()+1);i++) {
            c = fin.get();
            str.append(1,(char)c);
        }
        str.append(pw);
        fin.seekg(cpw.length(),ios::cur);

        while( (c=fin.get()) != EOF ) {
            str.append(1,(char)c);
        }
        fin.close();

        ofstream fout;
        fout.open("user_id.txt");
        if (!fout) {
            cout << "유저 정보 접근 실패";
            exit(0);
        }
        fout << str;
        fout.close();
    }


}
void Manager::deleteMember() {
    ifstream fin;
    fin.open("user_id.txt");

    if (!fin) {
        cout << "유저 정보 접근 실패";
        exit(0);
    }
    cout<<"삭제할 아이디를 입력하세요. >> ";
    string id,str="",str2="",cid="",cpw="";
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
                // 삭제할 아이디가 있음
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
        cout<<"삭제할 아이디가 존재하지 않습니다."<<endl;
    }
    else {
        ifstream fin;
        fin.open("user_id.txt");

        if (!fin) {
            cout << "유저 정보 접근 실패";
            exit(0);
        }
        fin.seekg(0,ios::beg);
        str = "";
        
        for (int i=0;i<fpos-(id.length()+cpw.length()+2);i++) {
            c = fin.get();
            str.append(1,(char)c);
        }
        fin.seekg(id.length()+cpw.length()+2,ios::cur);

        while( (c=fin.get()) != EOF ) {
            str.append(1,(char)c);
        }
        fin.close();
        cout<<str<<endl;

        ofstream fout;
        fout.open("user_id.txt");
        if (!fout) {
            cout << "유저 정보 접근 실패";
            exit(0);
        }
        fout << str;
        fout.close();
    }
}
void Manager::searchMember() {
    ifstream fin;
    fin.open("user_id.txt");

    if (!fin) {
        cout << "유저 정보 접근 실패";
        exit(0);
    }
    string str="",cid="";
    
    int c;
    while( (c=fin.get()) != EOF ) {
        if ((char)c == ':') {
            bool isID=true;
            for (char a: str) {
                if (a == ';') {
                    isID = false;
                    cid.append(1,',');
                    continue;
                }
                if (isID) {
                    cid.append(1,a);
                }
            }
            str = "";
        }
        else {
            str.append(1,(char)c);
        }
    }
    cout<<cid<<endl;
}