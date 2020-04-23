#ifndef PLAYER
#define PLAYER
#include "GenericPlayer.h"

//Игрок
class Player : public GenericPlayer{
public:
    Player(const string& n = "");

    virtual ~Player() override;

    //Нужна ли игроку еще одна карта
    virtual bool IsHitting() const override;

    //Вывод: Выиграл
    void Win() const;

    //Вывод: Проиграл
    void Lose() const;

    //Вывод: Ничья
    void Push() const;
};

#endif // PLAYER
