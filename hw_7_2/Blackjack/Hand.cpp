#include "Hand.h"
#include <iostream>

Hand::~Hand() {
    Clear();
}

//Добавляет карту в руку
void Hand::Add(Card* card) {
    cards.push_back(card);
}

//Очистка руки от карт
void Hand::Clear() {
    vector<Card*>::iterator it = cards.begin();
    for(; it != cards.end(); ++it) {
        delete *it;
    }

    cards.clear();
}

//Сумма очков карт руки
int Hand::GetTotal() const {
    if (cards.empty()) {
        cout << "Массив карт пустой";
        return 0;
    }

//    if (cards[0]->GetValue() == 0) {
//        return 0;
//    }

    int sum = 0;
    vector<Card*>::const_iterator it = cards.begin();
    for(; it != cards.end(); ++it) {
        int value = (*it)->GetValue();
        if (value == Rank::ace) {
            if (sum + 11 <= 21) {
                sum += 11;
            }
            else {
                sum += 1;
            }
        }
        else {
            sum += value;
        }
    }

    return sum;
}
