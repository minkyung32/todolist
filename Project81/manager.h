#include "user.h"
#include <fstream>

class Manager {
    vector<User*> v;
public:
    void registMember(ofstream& fout,string id,string pw);
    void modifyPw(ofstream& fout,string id,string pw);
    void deleteMember(ofstream& fout, string id);
    void searchMember(ofstream& fout, string id);
};