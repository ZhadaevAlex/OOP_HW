#include "Card.h"

Card::Card(Suit s, Rank r, bool f) : suit(s), rank(r), IsFaceUp(f) {}

//Переворачивает карту рубашкой вверх/аниз
void Card::Flip() {
     IsFaceUp = !IsFaceUp;
}

//Возвращает достоинство карты. Если рубашкой вверх, то возвращает ноль
int Card::GetValue() const {
    int result = 0;

    if (IsFaceUp) {
        result = rank;

        if (rank > 10) {
            result = 10;
        }
    }

    return result;
}

//Перегрузка оператора вставки для текущего класса
ostream& operator<<(ostream& out, const Card& c) {
    string suits[] = { "clubs", "diamonds", "hearts", "spades" };

    string ranks[] = {"0", "ACE", "2", "3", "4", "5",
                      "6", "7", "8", "9", "10", "J", "Q", "K"};

    if (c.IsFaceUp) {
        out << suits[c.suit] << ' ';
        out << ranks[c.rank] << endl;
    }
    else {
        out << "XX" << endl;
    }

    return out;
}
