#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string strings[2];

typedef struct {
    int lower;
    int upper;
} Bounds;

int len(string str) {
    int length = 0;  
    for (int i = 0; str[i] != '\0'; i++)  
        length++;  
    return length;     
}  

void split (string str, char seperator) {
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= len(str)) {
        if (str[i] == seperator || i == len(str)) {
            endIndex = i;  
            string subStr = "";  
            subStr.append(str, startIndex, endIndex - startIndex);  
            strings[currIndex] = subStr;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
    }     
}  

int isInside(Bounds b1, Bounds b2) {
    if((b1.lower >= b2.lower && b1.upper <= b2.upper) || (b1.lower <= b2.lower && b1.upper >= b2.upper)) return 1;
    else return 0;
}

int isOverlapping(Bounds b1, Bounds b2) {
    if(b1.lower <= b2.upper && b2.lower <= b1.upper) return 1;
    else return 0;
}

int main() {
    string a, ptr, temp1, temp2;
    int fullOverlaps = 0, partialOverlaps = 0;
    Bounds p1, p2;
    while(1) {
        getline(cin, a);
        if(a == "q") {
            cout << fullOverlaps << " | " << partialOverlaps << '\n';
            return 0;
        }
        split(a, ',');
        temp1 = strings[0];
        temp2 = strings[1];

        split(temp1, '-');
        p1 = {stoi(strings[0]), stoi(strings[1])};

        split(temp2, '-');
        p2 = {stoi(strings[0]), stoi(strings[1])};
        
        if(isInside(p1, p2))
            fullOverlaps++;
        if(isOverlapping(p1, p2))
            partialOverlaps++;
    }
}