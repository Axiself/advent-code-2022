#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "../useful_funcs.h"
using namespace std;

const int MARKERSIZE = 14;

int main() {
    string a, res;
    int i, idx = 0, counter = 0;
    while(1) {
        getline(cin, a);
        i = 0;
        if(a == "q")
            return 0;
        for(i = 0; i < a.size()-MARKERSIZE+1; i++, counter++) {
            res = a.substr(i, MARKERSIZE);
            if(repeatedChars(res) == 0) break;
        }
        cout << i+MARKERSIZE << " | " << res << '\n';
    }
}