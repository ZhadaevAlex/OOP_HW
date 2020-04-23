#ifndef DECK_H
#define DECK_H
#include "Hand.h"
#include "GenericPlayer.h"

//Башмак
class Deck : public Hand {
public:
    Deck();
    
    //Создает стандартную колоду из 52 карт
    void Populate();
    
    //Тасует карты
    void Shuffle();

    //Раздает одну карту в руку
    void Deal (Hand& aHand);
    
    //Раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
    void AddltionalCards (GenericPlayer& aGenerlcPlayer);
};

#endif // DECK_H
