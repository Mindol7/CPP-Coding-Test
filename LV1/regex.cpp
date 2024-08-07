#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solution(string s){
    s = regex_replace(s, regex("zero"), "0");

    return stoi(s);
}