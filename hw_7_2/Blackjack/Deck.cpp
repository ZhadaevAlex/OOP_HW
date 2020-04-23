#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck() {
    cards.reserve(52);
    Populate();
}

//Создает стандартную колоду из 52 карт
void Deck::Populate() {
    Clear();

    for (int suit = Suit::clubs; suit <= Suit::spades; ++suit) {
        for (int rank = Rank::ace; rank <= Rank::king; rank++) {
            Add(new Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}

//Тасует карты
void Deck::Shuffle() {
    if (cards.empty()) {
        cout << "Массив карт пустой";
        return;
    }

    random_shuffle(cards.begin(), cards.end());
}

//Раздает одну карту в руку
void Deck::Deal (Hand& hand) {
    if (cards.empty()) {
        cout << "Массив карт пустой";
        return;
    }

    hand.Add(cards.back());
    cards.pop_back();
}

//Раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
void Deck::AddltionalCards (GenericPlayer& genericPlayer) {
    while(genericPlayer.IsHitting()) {
        Deal(genericPlayer);

        cout << genericPlayer;

        if (genericPlayer.IsBoosted()) {
            genericPlayer.Bust();
            break;
        }
    }
}

