//
// Created by 18483 on 2024/11/18.
//
// ¿¨ÂëÍøKamaCoder.Ìæ»»Êı×Ö
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ret;
    for(auto ch : s)
    {
        if(ch >='0' && ch <= '9')
            ret += "number";
        else
            ret += ch;
    }

    cout << ret << endl;

    return 0;
}