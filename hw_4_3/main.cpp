#include <iostream>
#include <vector>

using namespace std;
//4. Создать класс Card, описывающий карту в игре БлэкДжек.
//У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
//Сделать поля масть и значение карты типом перечисления (enum).
//Положение карты - тип bool. Также в этом классе должно быть два метода:
//* метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//* метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

//3. Реализовать класс Hand, который представляет собой коллекцию карт.
//В классе будет одно поле: вектор указателей карт (удобно использовать вектор,
//т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).
//Также в классе Hand должно быть 3 метода:
// - метод Add, который добавляет в коллекцию карт новую карту,
//   соответственно он принимает в качестве параметра указатель на новую карту
// - метод Clear, который очищает руку от карт
// - метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).

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

        cout << "Положение карты: вниз рубашкой" << endl;
        return 0;
    }
};

class Hand {
private:
    vector<Card*> cards;

public:
    void Add(Card* card) {
        cards.push_back(card);
    }

    void Clear() {
        cards.clear();
    }

    int GetValue() {
        int sum = 0;
        for(unsigned int i = 0; i < cards.size(); i++) {
            if (cards[i]->GetValue() == Rank::ace) {
                if (sum + 11 <= 21) {
                    sum += 11;
                }
                else {
                    sum += 1;
                }
            }
            else {
                sum += cards[i]->GetValue();
            }
        }

        return sum;
    }
};

int main()
{
    //Проверка ДЗ к уроку 3
    Suit suit = clubs;
    Rank rank = four;
    bool faceUp = true;
    Card card(suit, rank, faceUp);

    cout << card.GetValue() << endl;
    cout << endl;

    cout << "Перевернем карту" << endl;
    card.Flip();

    cout << card.GetValue() << endl;

    //Проверка ДЗ к уроку 4
    Hand hand;

    //Ситуация, когда туз равен 1
    hand.Add(new Card(Suit::clubs, Rank::four, true));
    hand.Add(new Card(Suit::clubs, Rank::seven, true));
    hand.Add(new Card(Suit::clubs, Rank::ace, true));

    cout << hand.GetValue() << endl;
    hand.Clear();

    //Ситуация, когда туз равен 11
    hand.Add(new Card(Suit::clubs, Rank::four, true));
    hand.Add(new Card(Suit::clubs, Rank::five, true));
    hand.Add(new Card(Suit::clubs, Rank::ace, true));
    cout << hand.GetValue() << endl;
    hand.Clear();

    return 0;
}
