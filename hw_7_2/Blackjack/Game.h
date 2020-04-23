#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "House.h"
#include "Deck.h"

//Игра
class Game {
private:
    //Колода карт
    Deck deck;

    //Рука дилера
    House house;

    //Группа игроков-людей
    vector<Player> players;

public:
    Game(const vector<string>& names);

    //Кон игры
    void play();
};

#endif // GAME_H
