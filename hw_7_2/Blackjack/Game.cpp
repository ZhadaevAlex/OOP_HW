#include "Game.h"
#include <iostream>

Game::Game(const vector<string>& names) {

    //Создание игроков
    vector<string>::const_iterator itNames;
    for (itNames = names.begin(); itNames !=names.end(); itNames++) {
        players.push_back(*new Player(*itNames));
    }

    deck.Populate();
    deck.Shuffle();
    deck.Shuffle();
}

void Game::play() {
    //Раздача карт игрокам
    vector<Player>::iterator itPlayer;
    for (itPlayer = players.begin(); itPlayer !=players.end(); ++itPlayer) {
        for (int i = 0; i < 2; ++i) {
            deck.Deal(*itPlayer);
        }
    }

    //Раздача первой карты дилеру
    deck.Deal(house);

    //Переворот первой карты дилера
    house.FlipFirstCard();

    //Раздача дилеру второй карты
    deck.Deal(house);

    //Вывод карт игроков
    for (itPlayer = players.begin(); itPlayer !=players.end(); ++itPlayer) {
        cout << *itPlayer << endl;
    }

    //Вывод карт дилера
    cout << house << endl;

    //Раздача карт игрокам
    for (itPlayer = players.begin(); itPlayer !=players.end(); ++itPlayer) {
        deck.AddltionalCards(*itPlayer);
        cout << endl;
    }

    //Переворот первой карты дилера
    house.FlipFirstCard();

    //Вывод карт дилера
    cout << house << endl;

    //Дилер добирает карты
    deck.AddltionalCards(house);
    cout << endl;

    //Вывод результатов
    if (house.IsBoosted()) {
        for (itPlayer = players.begin(); itPlayer !=players.end(); ++itPlayer) {
            if (!itPlayer->IsBoosted()) {
                itPlayer->Win();
            }
            else {
                itPlayer->Lose();
            }
        }
    }
    else {
        for (itPlayer = players.begin(); itPlayer !=players.end(); ++itPlayer) {
            if (itPlayer->GetTotal() > house.GetTotal()) {
                itPlayer->Win();
            }
            else if (itPlayer->GetTotal() < house.GetTotal()) {
                itPlayer->Lose();
            }
            else {
                itPlayer->Push();
            }
        }
    }

    //Очистка рук
    for (itPlayer = players.begin(); itPlayer !=players.end(); ++itPlayer) {
        itPlayer->Clear();
    }

    house.Clear();
}
