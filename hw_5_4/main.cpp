#include <iostream>
#include <vector>

using namespace std;
//4. Написать перегрузку оператора вывода для класса Card.
//Если карта повернута рубашкой вверх (мы ее не видим), вывести ХХ,
//если мы ее видим, вывести масть и номинал карты.

//5. Согласно иерархии классов, которая представлена в методичке к уроку 3,
//от класса Hand наследует класс GenericPlayer, который обощенно представляет игрока,
//ведь у нас будет два типа игроков - человек и компьютер.
//Создать класс GenericPlayer, в который добавить поле name - имя игрока.
//Также добавить 3 метода:
// - IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
// - IsBoosted() - возвращает bool значение, есть ли у игрока перебор.
// - Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
//Также для класса GenericPlayer написать перегрузку оператора вывода,
//который должен отображать имя игрока и его карты, а также общую сумму очков его карт.

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

    int GetValue() const {
        if (faceUp) return rank;

        cout << "Положение карты: вниз рубашкой" << endl;
        return 0;
    }

    friend ostream& operator<<(ostream& out, Card& c) {
        if (c.faceUp) {
            switch (c.suit) {
                case clubs: return out << "clubs" << ' ' << c.rank << endl;
                case diamonds: return out << "diamonds" << ' ' << c.rank << endl;
                case hearts: return out << "hearts" << ' ' << c.rank << endl;
                case spades: return out << "spades" << ' ' << c.rank << endl;
            }
        }

        return out << "XX" << endl;
    }
};

class Hand {
protected:
    vector<Card*> cards;

public:
    void Add(Card* card) {
        cards.push_back(card);
    }

    void Clear() {
        vector<Card*>::iterator it = cards.begin();

        for(; it < cards.end(); it++) {
            delete *it;
        }

        cards.clear();
    }

    int GetValue() const {
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

class GenericPlayer : public Hand {
private:
    string name;

public:
    GenericPlayer(string n) : name(n) {}

    virtual ~GenericPlayer() {}

    virtual bool IsHitting() = 0;

    bool IsBoosted() {
        if (GetValue() > 21) return true;

        return false;
    }

    void Bust() {
        cout << name << ": Перебор" << endl;
    }

    friend ostream& operator<<(ostream& out, GenericPlayer& gp) {

        out << "Имя игрока: " << gp.name << '\n';
        out << "Карты игрока: " << '\n';

        vector<Card*>::iterator it = gp.cards.begin();
        for(; it < gp.cards.end(); it++) {
            out << **it;
        }

        out << "Сумма очков карт: " << gp.GetValue() << '\n';

        if (gp.IsBoosted()) {
            out << "Перебор" << '\n';
        }

        return out;
    }
};

class Player : public GenericPlayer{
public:
    Player(string name) : GenericPlayer(name) {}
    virtual ~Player() override{}

    bool IsHitting() override {
        if (cards.size() < 2 || GetValue() <= 16) {
            return true;
        }

        return false;
    }
};

class House : public GenericPlayer{
public:
    virtual ~House() override {}

    bool IsHitting() override {
        if (cards.size() < 2) {
            return true;
        }

        return false;
    }
};

int main()
{
    cout << "Проверка ДЗ к уроку 3" << endl;
    Suit suit = clubs;
    Rank rank = four;
    bool faceUp = true;
    Card card(suit, rank, faceUp);

    cout << card.GetValue() << endl;

    cout << "Перевернем карту" << endl;
    card.Flip();

    cout << card.GetValue() << endl;
    cout << endl;

    cout << "Проверка ДЗ к уроку 4" << endl;
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
    cout << endl;

    cout << "Проверка ДЗ к уроку 5. Задача 4" << endl;
    Card card1(Suit::clubs, Rank::four, true);
    cout << card1;
    cout << "Перевернем карту" << endl;
    card1.Flip();
    cout << card1;
    cout << endl;

    cout << "Проверка ДЗ к уроку 5. Задача 5" << endl;
    Player player("Иван");

    player.Add(new Card(Suit::clubs, Rank::four, true));
    player.Add(new Card(Suit::diamonds, Rank::seven, true));
    player.Add(new Card(Suit::hearts, Rank::ace, true));
    cout << player;
    cout << endl;

    cout << "Организуем перебор" << endl;

    player.Add(new Card(Suit::spades, Rank::ten, true));
    cout << player;

    return 0;
}
