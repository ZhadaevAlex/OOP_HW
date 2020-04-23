#ifndef CARD_H
#define CARD_H
#include "Suit.h"
#include "Rank.h"
#include <ostream>

using namespace std;

//Карта
class Card {
    Suit suit;
    Rank rank;
    bool IsFaceUp;

public:
    Card(Suit s, Rank r, bool f = true); //f - true - карта рубашкой вниз

    //Переворачивает карту рубашкой вверх/аниз
    void Flip();

    //Возвращает достоинство карты. Если рубашкой вверх, то возвращает ноль
    int GetValue() const;

    //Перегрузка оператора вставки для текущего класса
    friend ostream& operator<<(ostream& out, const Card& c);
};

#endif // CARD_H
