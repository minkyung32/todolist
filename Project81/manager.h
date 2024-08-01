#include "user.h"
#include <fstream>

class Manager {
    vector<User*> v;
public:
    void registMember(ofstream& fout);
    void modifyPw(ifstream& fin,ofstream& fout);
    void deleteMember(ofstream& fout, string id);
    void searchMember(ofstream& fout, string id);
};
