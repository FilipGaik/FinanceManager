#include "User.h"

void User::setId(int newId) {
    if (newId >= 0){
        id = newId;
    }
}

void User::setLogin(string newLogin) {
    if ((int) newLogin.size() > 0){
        login = newLogin;
    }
}

void User::setPassword(string newPassword) {
    if ((int) newPassword.size() > 0){
        password = newPassword;
    }
}

void User::setName(string newName) {
    if ((int) newName.size() > 0){
        name = newName;
    }
}

void User::setSurname(string newSurname) {
    if ((int) newSurname.size() > 0){
        surname = newSurname;
    }
}

int User::getId() {
    return id;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}
