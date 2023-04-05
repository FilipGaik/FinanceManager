#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "UserFile.h"
#include "User.h"

using namespace std;

class UserManager {
    int idOfLoggedUser;
    vector <User> users;
    UserFile userFile;

public:
    UserManager(string usersFileName) : userFile(usersFileName) {
        idOfLoggedUser = 0;
        users = userFile.loadUsers();
    };
    int getIdOfLoggedUser();
    void setIdOfLoggedUser(int newId);
    void registration();
    void logIn ();
    void changePassword();
};

#endif
