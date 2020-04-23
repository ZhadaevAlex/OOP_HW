#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <vector>

//Рука
class Hand {
protected:

    //Коллекция карт руки
    vector<Card*> cards;

public:
    ~Hand();

    //Добавляет карту в руку
    void Add(Card* card);

    //Очистка руки от карт
    void Clear();

    //Сумма очков карт руки
    int GetTotal() const;
};

#endif // HAND_H
