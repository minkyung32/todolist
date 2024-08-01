#include "user.h"
#include <fstream>

class Manager {
    vector<User*> v;
public:
    void registMember();
    void modifyPw();
    void deleteMember();
    void searchMember();
};
