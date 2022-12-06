#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "../useful_funcs.h"
using namespace std;

const int START = 1;
const int GAP = 4;

int main() {
    vector<vector<char>> table, table2;
    vector<int> vec;
    string action[6];
    string a;
    int col, i, temp, amount, from, to;
    while(1) {
        getline(cin, a);

        if(table.empty()) //Initializing the table
            for(col = 0; col < (a.length()+1)/4; col++) {
                table.push_back({});
                table2.push_back({});
            }

        if(a[0] == '[') { //Adding elements to the table
            for(col = 0; col < table.size(); col++) {
                if(a[START+col*GAP] != ' ') {
                    table[col].insert(table[col].begin(), a[START+col*GAP]);
                    table2[col].insert(table2[col].begin(), a[START+col*GAP]);
                }
            }
        } else if(a[0] == 'm') {
            split(a, ' ', action);
            amount = stoi(action[1]);
            from = stoi(action[3])-1;
            to = stoi(action[5])-1;
            for(i = 0; i < amount; i++) {
                //Part 1
                temp = table[from][table[from].size()-1];
                table[from].pop_back();
                table[to].push_back(temp);

                //Part 2
                vec.push_back(table2[from][table2[from].size()-1]);
                table2[from].pop_back();
            }
            for(i = vec.size()-1; !vec.empty(); i--) {
                table2[to].push_back(vec[i]);
                vec.pop_back();
            }
        } else if(a[0] == 'q') {
            printTable(table);
            cout << "-------------------------------------------\n";
            printTable(table2);
            return 0;
        }
    }
}