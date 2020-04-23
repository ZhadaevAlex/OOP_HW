#include <iostream>
#include "Player.h"

Player::Player(const string& n) : GenericPlayer(n) {}

Player::~Player() {}

//Нужна ли игроку еще одна карта
bool Player::IsHitting() const {
    if (cards.size() < 2) {
            return true;
    }

    while (1) {
        string str;

        cout << this->name << "," << "Еще? (д/н y/n): " << endl;

        getline(cin, str);

        if (str == "д" || str == "y") {
            return true;
        }

        if (str == "н" || str == "n") {
            return false;
        }

        cout << "Неверный ввод. Введите д/н y/n: ";
    }
}

//Вывод: Выиграл
void Player::Win() const {
    cout << name << " выиграл(а)" << endl;
}

//Вывод: Выиграл
void Player::Lose() const {
    cout << name << " проиграл(а)" << endl;
}

//Вывод: Ничья
void Player::Push() const {
    cout << name << " сыграл(а) вничью" << endl;
}
