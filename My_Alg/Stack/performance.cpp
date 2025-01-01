#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    const int NUM_ELEMENTS = 10000000;
    map<int, int> orderedMap;
    unordered_map<int, int> unorderedMap;

    clock_t start, end;

    start = clock();
    for(int i = 0; i<NUM_ELEMENTS; ++i){
        orderedMap[i] = rand();
    }
    end = clock();

    cout<<"Map Insertion Time : "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;

    start = clock();
    for(int i = 0; i<NUM_ELEMENTS; ++i){
        unorderedMap[i] = rand();
    }
    end = clock();

    cout<<"Unordered Map Insertion Time : "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;

    return 0;
}