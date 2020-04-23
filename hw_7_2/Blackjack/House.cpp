#include "House.h"
#include <iostream>

House::House(const string n) : GenericPlayer(n) {}

House::~House() {}

//Нужна ли игроку еще одна карта
bool House::IsHitting() const {
    return GetTotal() <= 16;
}

//Переворачивает первую карту
void House::FlipFirstCard() {
    if (cards.empty()) {
        cout << "Массив карт пустой";
        return;
    }

    cards[0]->Flip();
}

