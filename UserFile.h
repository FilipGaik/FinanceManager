#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "xmlFile.h"
#include "User.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class UserFile : public xmlFile {
public:
    UserFile(string usersFileName)
    : xmlFile(usersFileName) {};
    vector<User> loadUsers();
    string getRegisteredUsersFileName();
    void addNewUser(User newUser);
    void saveNewPassword(string newPassword, int idOfLoggedUser);
};

#endif
