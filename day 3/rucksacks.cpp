#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int charValue(char a) {
    if(isupper(a)) return int(a) - 65 + 27;
    else return int(a) - 97 + 1;
}

int main() {
    string a, half, otherhalf, foundLetters, groupLetters, temp;
    int total1 = 0, total2 = 0, groupCount = 0, i, j;
    while(1) {
        getline(cin, a);
        if(a == "q") {
            cout << total1 << " | " << total2 << '\n';
            return 0;
        }
        groupCount++;
        half = a.substr(0, a.length()/2);
        otherhalf = a.substr(a.length()/2);
        foundLetters = "";

        if(groupCount == 1)
            groupLetters = a;

        //Checking for common letters in rucksacks
        for(i = 0; i < half.length(); i++) {
            if(otherhalf.find(half[i]) != string::npos && foundLetters.find(half[i]) == string::npos) {
                total1 += charValue(half[i]);
                foundLetters.push_back(half[i]);
                //cout << "Found " << half[i] << '\n';
            }
        }

        //Checking for group badge
        if(groupCount > 1) {
            temp = "";
            for(i = 0; i < a.length(); i++) {
                if(groupLetters.find(a[i]) != string::npos)
                    temp.push_back(a[i]);
            }
            groupLetters = temp;
        }

        //At the end of a group block
        if(groupCount == 3) {
            //cout << groupLetters << '\n';
            total2 += charValue(groupLetters[0]);
            groupCount = 0;
        }
    }
}