#ifndef HOUSE_H
#define HOUSE_H
#include "GenericPlayer.h"

//Дилер
class House : public GenericPlayer{
public:
    House(const string n = "Дилер");
    virtual ~House() override;

    //Нужна ли игроку еще одна карта
    bool IsHitting() const override;

    //Переворачивает первую карту
    void FlipFirstCard();
};

#endif // HOUSE_H
