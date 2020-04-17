#include <iostream>
#include <vector>

using namespace std;

//4. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
// - `virtual bool IsHitting() const` - реализация чисто виртуальной функции базового класса.
//    Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде `true` или `false`.
// - `void Win() const` - выводит на экран имя игрока и сообщение, что он выиграл.
// - `void Lose() const` - выводит на экран имя игрока и сообщение, что он проиграл.
// - `void Push() const` - выводит на экран имя игрока и сообщение, что он сыграл вничью.

//5. Реализовать класс `House`, который представляет дилера.
//Этот класс наследует от класса `GenericPlayer`. У него есть 2 метода:
// - virtual bool IsHitting() const - метод указывает,
//   нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
// - void FlipFirstCard() - метод переворачивает первую карту дилера.


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

        return 0;
    }

    friend ostream& operator<<(ostream& out, Card& c) {
        if (c.faceUp) {
            switch (c.suit) {
                case clubs:
                    out << "clubs";
                    break;

                case diamonds:
                    out << "diamonds";
                    break;

                case hearts:
                    out << "hearts";
                    break;

                case spades:
                    out << "spades";
                    break;
            }

            out << ' ' << c.rank << endl;
        }
        else {
            out << "XX" << endl;
        }

        return out;
    }
};

class Hand {
protected:
    vector<Card*> cards;

public:
    ~Hand() {
        Clear();
    }

    void Add(Card* card) {
        cards.push_back(card);
    }

    void Clear() {
        vector<Card*>::iterator it = cards.begin();

        for(; it != cards.end(); it++) {
            delete *it;
        }

        cards.clear();
    }

    int GetValue() const {
        int sum = 0;
        for(unsigned int i = 0; i < cards.size(); i++) {
            int value = cards[i]->GetValue();
            if (value != 0) {
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
        }

        return sum;
    }
};

class GenericPlayer : public Hand {
protected:
    string name;

public:
    GenericPlayer(string n = "Дилер") : name(n) {}

    virtual ~GenericPlayer() {}

    virtual bool IsHitting() = 0;

    bool IsBoosted() const {
        return GetValue() > 21;
    }

    void Bust() const {
        cout << name << ": Перебор" << endl;
    }

    friend ostream& operator<<(ostream& out, GenericPlayer& gp) {

        out << "Имя игрока: " << gp.name << '\n';
        out << "Карты игрока: " << '\n';

        vector<Card*>::iterator it = gp.cards.begin();
        for(; it != gp.cards.end(); it++) {
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
    Player(string n) : GenericPlayer(n) {}
    virtual ~Player() override{}

    virtual bool IsHitting() override{
        if (cards.size() < 2) {
                return true;
        }

        while (1) {
            string str;

            cout << "Еше? (д/н y/n): ";

            getline(cin, str);

            if (str == "д" || str == "y") {
                return true;
            }

            if (str == "н" || str == "n") {
                return false;
            }

            cout << "Неверный ввод. Введите д/н y/n: ";
        }
    }

    void Win() const {
        cout << name << " выиграл(а)" << endl;
    }

    void Lose() const {
        cout << name << " проиграл(а)" << endl;
    }

    void Push() const {
        cout << name << " сыграл(а) вничью" << endl;
    }
};

class House : public GenericPlayer{
public:
    virtual ~House() override {}

    bool IsHitting() override {
        if (GetValue() <= 16) {
            return true;
        }

        return false;
    }

    void FlipFirstCard() {
        if (cards.size() == 1) {
            cards[0]->Flip();
        }
    }
};

int main()
{
    cout << "Проверка ДЗ к уроку 6. Задача 4" << endl;
    cout << "Создадим игрока Иван" << endl;
    Player player("Иван");
    cout << "У Ивана нет карт" << endl;
    cout << "Результат IsHitting(): " << player.IsHitting() << endl;

    cout << "Иван взял одну карту" << endl;
    player.Add(new Card(Suit::clubs, Rank::four, false));
    cout << "Результат IsHitting(): " << player.IsHitting() << endl;

    cout << "Иван взял еще одну карту" << endl;
    player.Add(new Card(Suit::clubs, Rank::six, false));
    cout << "Результат IsHitting(): " << player.IsHitting() << endl;

    player.Win();
    player.Lose();
    player.Push();

    cout << endl;

    cout << "Создадим Дилера" << endl;
    House house;
    cout << "У дилера меньше 16-ти очков (нет карт)" << endl;
    cout << "Результат IsHitting(): " << house.IsHitting() << endl;

    cout << "Дилер взял одну карту. Покажем ее" << endl;
    house.Add(new Card(Suit::clubs, Rank::ten, false));
    cout << house;
    cout << endl;

    cout << "Перевернем и снова покажем" << endl;
    house.FlipFirstCard();
    cout << house;

    cout << "Дилер не набрал 16 очков" << endl;
    cout << "Результат IsHitting(): " << house.IsHitting() << endl;
    cout << endl;

    cout << "Дилер взял еще одну карту" << endl;
    house.Add(new Card(Suit::clubs, Rank::seven, true));
    cout << house;
    cout << endl;

    cout << "Дилер набрал больше 16-ти очков" << endl;
    cout << "Результат IsHitting(): " << house.IsHitting() << endl;
    cout << endl;

    return 0;
}

