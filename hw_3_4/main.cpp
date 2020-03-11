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
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
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
    Card(Suit s, Rank r) : suit(s), rank(r) {}

    bool Flip() {
        return !faceUp;
    }

    int GetValue() {
        return rank;
    }
};

int main()
{
    Card card(Suit::clubs, Rank::king);

    cout << card.GetValue() << endl;

    return 0;
}
