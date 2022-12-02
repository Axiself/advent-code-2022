#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

typedef struct {
    string win;
    string tie;
    string lose;
} RockPaperScissors;

RockPaperScissors rock = {"scissors", "rock", "paper"};
RockPaperScissors paper = {"rock", "paper", "scissors"};
RockPaperScissors scissors = {"paper", "scissors", "rock"};

int roundOutcome(string a, RockPaperScissors opponent) {
    if(a == opponent.win) return 0;
    else if(a == opponent.tie) return 3;
    else return 6;
}

int playValue(string a) {
    if(a == "rock") return 1;
    else if(a == "paper") return 2;
    else return 3;
}

int main() {
    string a;
    RockPaperScissors player;
    int score1 = 0, score2 = 0;
    while(1) {
        getline(cin, a);
        switch (a[0]) {
        case 'A':
            player = rock;
            break;
        case 'B':
            player = paper;
            break;
        case 'C':
            player = scissors;
            break;
        case 'q':
            cout << "1 : " << score1 << " | 2 : " << score2 << "\n";
            return 0;
        default:
            break;
        }

        switch (a[2])
        {
        case 'X':
            score1 += 1 + roundOutcome("rock", player);
            score2 += playValue(player.win);
            break;
        case 'Y':
            score1 += 2 + roundOutcome("paper", player);
            score2 += 3 + playValue(player.tie);
            break;
        case 'Z':
            score1 += 3 + roundOutcome("scissors", player);
            score2 += 6 + playValue(player.lose);
            break;
        default:
            break;
        }
    }
    return 0;
}