#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit {club, diamond, heart, spade};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card{
    int number;
    Suit suit;

    public:
        void set(int num, Suit s)
            {number = num; suit = s;}
        void display();
};

void card::display(){
    if(number >= 2 && number <= 10)
        cout << number;
    else {
        switch(number) {
            case jack: cout << 'J'; break;
            case queen: cout << 'Q'; break;
            case king: cout << 'K'; break;
            case ace: cout << 'A'; break;
        }
    }

    switch(suit) {
        case 0: cout << static_cast<char>(5); break;
        case 1: cout << static_cast<char>(4); break;
        case 2: cout << static_cast<char>(3); break;
        case 3: cout << static_cast<char>(6); break;
    }
}

int main() {
    card deck[52];

    for(int i = 0; i < 52; ++i)
        //Suit s = (Suit)(i/13);
        //char c = (char)1;
        deck[i].set(i % 13 + 2, Suit(i/13));

    cout << "Ordered Deck:\n";

    for(int i = 0; i < 52; ++i) {
        deck[i].display();
        cout << ' ';

        if(!((i+1)%13))
            cout << endl;
    }

    cout << endl;

    srand(time(nullptr));
    for(int i = 0; i < 52; ++i) {
        int j = rand() % 52;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    cout << "Shuffled Deck:\n";

    for(int i = 0; i < 52; ++i) {
        deck[i].display();
        cout << ' ';

        if(!((i+1)%13))
            cout << endl;
    }

    return 0;
}