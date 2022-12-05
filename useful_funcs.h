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