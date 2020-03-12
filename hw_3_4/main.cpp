#include <iostream>

using namespace std;
//4. Создать класс Card, описывающий карту в игре БлэкДжек.
//У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
//Сделать поля масть и значение карты типом перечисления (enum).
//Положение карты - тип bool. Также в этом классе должно быть два метода:
//* метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//* метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

enum Suit { //Масть
    clubs,
    diamonds,
    hearts,
    spades
};

enum Rank { //Достоинство
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten = 10,
    jack = 10,
    queen = 10,
    king = 10
};

class Card {
    Suit suit;
    Rank rank;
    bool faceUp;
public:
    Card(Suit s, Rank r, bool f) : suit(s), rank(r), faceUp(f) {}

    void Flip() {
         faceUp = !faceUp;
    }

    int GetValue() {
        if (faceUp) return rank;

        cout << "Положение карты: вверх рубашкой" << endl;
        return 0;
    }
};

int main()
{
    Suit suit = clubs;
    Rank rank = four;
    bool faceUp = true;

    Card card(suit, rank, faceUp);

    cout << card.GetValue() << endl;
    cout << endl;

    cout << "Перевернем карту" << endl;
    card.Flip();

    cout << card.GetValue() << endl;

    return 0;
}
