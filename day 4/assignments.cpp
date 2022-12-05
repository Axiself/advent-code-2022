#include <stdio.h>
#include <string>
#include <iostream>
#include "../useful_funcs.h"
using namespace std;

typedef struct {
    int lower;
    int upper;
} Bounds;

int isInside(Bounds b1, Bounds b2) {
    if((b1.lower >= b2.lower && b1.upper <= b2.upper) || (b1.lower <= b2.lower && b1.upper >= b2.upper)) return 1;
    else return 0;
}

int isOverlapping(Bounds b1, Bounds b2) {
    if(b1.lower <= b2.upper && b2.lower <= b1.upper) return 1;
    else return 0;
}

int main() {
    string a, ptr, temp1, temp2, strings[2];
    int fullOverlaps = 0, partialOverlaps = 0;
    Bounds p1, p2;
    while(1) {
        getline(cin, a);
        if(a == "q") {
            cout << fullOverlaps << " | " << partialOverlaps << '\n';
            return 0;
        }
        split(a, ',', strings);
        temp1 = strings[0];
        temp2 = strings[1];

        split(temp1, '-', strings);
        p1 = {stoi(strings[0]), stoi(strings[1])};

        split(temp2, '-', strings);
        p2 = {stoi(strings[0]), stoi(strings[1])};
        
        if(isInside(p1, p2))
            fullOverlaps++;
        if(isOverlapping(p1, p2))
            partialOverlaps++;
    }
}