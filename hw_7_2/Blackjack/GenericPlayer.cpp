#include <iostream>
#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string& n) : name(n) {}

GenericPlayer::~GenericPlayer() {}

//Перебор
bool GenericPlayer::IsBoosted() const {
    return GetTotal() > 21;
}

//Вывод информации о событии Перебор
void GenericPlayer::Bust() const {
    cout << name << ": Перебор" << endl;
}

//Перегрузка оператора вставки для текущего класса
ostream& operator<<(ostream& out, GenericPlayer& gp) {
    out << "Имя игрока: " << gp.name << '\n';
    out << "Карты игрока: " << '\n';

    if (gp.cards.empty()) {
        out << "Массив карт пустой";
    }
    else {
        vector<Card*>::iterator it = gp.cards.begin();
        for(; it != gp.cards.end(); it++) {
            out << **it;
        }

        out << "Сумма очков карт: " << gp.GetTotal() << '\n';
    }

    return out;
}
