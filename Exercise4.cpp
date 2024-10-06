// Arda Barak 
// 300129340

#include <iostream>
using namespace std;

//suits
enum Suit {Clubs, Diamonds, Hearts, Spades};
//ranks
enum Rank {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card {
    Rank rank;
    Suit suit;
};

bool checkPair(Card hand[5]) {  //check for a pair
    int rankCount[13] = {0};    //array for flag rank counts
    for (int i = 0; i < 5; i++) 
    {
        rankCount[hand[i].rank - 2]++;
    }
    for (int i = 0; i < 13; i++) 
    {
        if (rankCount[i] == 2) { //check for pairs
            return true;
        }
    }
    return false;
}

int main() {
    Card hand[5] = {
        {Ace, Spades},
        {Ace, Hearts},
        {Jack, Clubs},
        {Nine, Diamonds},
        {Six, Diamonds}
    };
    
    if (checkPair(hand)) {
        cout << "We've a pair" << endl;
    } else {
        cout << "We've no pairs" << endl;
    }
    return 0;
}
