#include "UserManager.h"

int UserManager::getIdOfLoggedUser() {
    return idOfLoggedUser;
}

void UserManager::setIdOfLoggedUser(int newId) {
    if (newId >= 0){
        idOfLoggedUser = newId;
    }
}

void UserManager::registration() {
    User newUser;
    string login, password;
    cout << "Enter your name: ";
    newUser.setName(AuxiliaryFunctions::readLine());
    cout << "Enter your surname: ";
    newUser.setSurname(AuxiliaryFunctions::readLine());
    cout << "Enter your login: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << "This login is already taken. Enter different login: ";
            cin >> login;
            i = -1;
        }
    }

    cout << "Enter password: ";
    cin >> password;
    newUser.setLogin(login);
    newUser.setPassword(password);
    newUser.setId(users.size() == 0 ? 1 : users.back().getId() + 1);
    users.push_back(newUser);
    userFile.addNewUser(newUser);

    cout << "Account created." << endl;
    system("pause");
}

void UserManager::logIn () {
    string login, password;
    bool thereIsAUser = false;

    cout << "Enter your login: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            thereIsAUser = true;
            for (int j = 0; j < 3; j++) {
                cout << "Enter your password (trials left - " << 3 - j << "): ";
                cin >> password;
                if (password == users[i].getPassword()) {
                    cout << "You have logged in." << endl;
                    system("pause");
                    idOfLoggedUser = users[i].getId();
                    return;
                }
            }
            if (idOfLoggedUser == 0) {
                cout << "You entered the wrong password 3 times." << endl;
                system("pause");
                return;
            }
        }
    }
    if (!thereIsAUser) {
        cout << "There is no user with entered login." << endl;
        system("pause");
    }
}

void UserManager::changePassword() {
    string password;
    cout << "Enter new password: ";
    cin >> password;
    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getId() == idOfLoggedUser) {
            users[i].setPassword(password);
            userFile.saveNewPassword(password, idOfLoggedUser);
            cout << "Password has been changed." << endl;
            system("pause");
            break;
        }
    }
}
