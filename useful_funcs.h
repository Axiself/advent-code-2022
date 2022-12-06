#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*------------------------------------------DAY 3------------------------------------------*/

int len(string str) {
    int length = 0;  
    for (int i = 0; str[i] != '\0'; i++)  
        length++;  
    return length;     
}  

void split (string str, char seperator, string strings[]) {
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

/*------------------------------------------DAY 5------------------------------------------*/

int findChar(vector<char> v, char key) {
    for(int i = 0; i < v.size(); i++)
        if(v[i] == key)
            return i;
    return -1;
}

void printCharVector(vector<char> v) {
    cout << "[ ";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "]\n";
}

void deleteCharVector(vector<char> v) {
    for(int i = 0; i < v.size(); i++)
        v.pop_back();
}

int repeatedChars(string s) {
    int count;
    for (int i= 0; i < s.size(); i++) {
        count = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[i] == s[j])
                count++;
        }
        if(count > 1)
            return 1;
    }
    return 0;
}