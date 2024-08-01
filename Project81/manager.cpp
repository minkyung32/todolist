#include "manager.h"

void registMember(ofstream& fout,string id, string pw) {
    cout << "New User Regist" << endl;
    ofstream fout("user_id.txt", ios::out | ios::app);
    if (!fout) {
        cout << "File not Found" << endl;
        return;
    }
    fout << id << ':' << pw << endl;
    fout.close();
}

void modifyPw(ofstream& fout,string id,string pw) {
    
}
void deleteMember(ofstream& fout, string id) {

}
void searchMember(ofstream& fout, string id) {

}