#include "UserFile.h"

vector<User> UserFile::loadUsers() {
    vector<User> users;
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User")) {
        User user;
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setId(stoi(xml.GetData()));
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}

string UserFile::getRegisteredUsersFileName() {
    return FILENAME;
}

void UserFile::addNewUser(User newUser) {
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", newUser.getId());
    xml.AddElem("Name", newUser.getName());
    xml.AddElem("Surname", newUser.getSurname());
    xml.AddElem("Login", newUser.getLogin());
    xml.AddElem("Password", newUser.getPassword());
    xml.OutOfElem();
    xml.Save(FILENAME);
}

void UserFile::saveNewPassword(string newPassword, int idOfLoggedUser) {
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (stoi(xml.GetData()) == idOfLoggedUser) {
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", newPassword);
            xml.OutOfElem();
            xml.Save(FILENAME);
            break;
        }
        xml.OutOfElem();
    }
}
