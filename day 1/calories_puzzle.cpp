#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


int main() {
    int current = 0;
    int max = 0;
    string a;
    while(1) {
        //cin >> a;
        getline(cin, a);
        if(a == "") {
            if(current > max)
                max = current;
            current = 0;
        } else if(a == "q") {
            cout << max;
            cout << '\n';
            return 0;
        } else {
            current += stoi(a);
        }
    }

}