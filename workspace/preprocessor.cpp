#include <bits/stdc++.h>
#include <string>

#pragma once

using namespace std;

#define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT_FUNC(x) cout<<"[DEBUG] "<<__FILE__<<":"<<__LINE__<<x<<endl;
#else
    #define DEBUG_PRINT_FUNC(x)
#endif

void calculate(int a, int b){
    int result = a + b;
    DEBUG_PRINT_FUNC("a = "<<a);
    DEBUG_PRINT_FUNC("b = "<<b);
    DEBUG_PRINT_FUNC("result = "<<result);
}

int main(){
    calculate(5, 10);

    return 0;
}