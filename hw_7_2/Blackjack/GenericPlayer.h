#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include "Hand.h"

//Обобщение игрока (игрок/дилер)
class GenericPlayer : public Hand {
protected:
    string name;

public:
    GenericPlayer(const string& n = "");

    virtual ~GenericPlayer();

    //Нужна ли игроку еще одна карта
    virtual bool IsHitting() const = 0;

    //Перебор
    bool IsBoosted() const;

    //Вывод: Перебор
    void Bust() const;

    //Перегрузка оператора вставки для текущего класса
    friend ostream& operator<<(ostream& out, GenericPlayer& gp);
};

#endif // GENERICPLAYER_H
