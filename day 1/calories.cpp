#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int current = 0;
    int max[3] = {0,0,0};
    int pos, i, r, flag = 0;
    string a;
    while(1) {
        getline(cin, a);
        if(a == "") {
            flag = 0;
            for(i = 0; i < 3; i++) {
                if(current >= max[i]) {
                    pos = i;
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                for(i = 2; i > pos; i--)
                    max[i] = max[i-1];
                max[pos] = current;
            }
            current = 0;
        } else if(a == "q") {
            r = max[0]+max[1]+max[2];
            cout << r << "\n";
            return 0;
        } else {
            current += stoi(a);
        }
    }
}