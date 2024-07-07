#include <iostream>

using namespace std;

int main(){
    int intArray[3] = {1, 2, 3};
    double doubleArray[3] = {1.1, 2.2, 3.3};
    char charArray[3] = {'a', 'b', 'c'};

    for(auto i : intArray){
        cout<<i<<endl;
    }

    for(int i = 0; i < 3; i++){
        cout<<&intArray[i]<<endl;
    }

    for(int j = 0; j < 3; j++){
        cout<<&doubleArray[j]<<endl;
    }

    for(int k = 0; k < 3; k++){
        cout<<&charArray[k]<<endl;
    }

    for(int i = 0; i < 3; i++){
        cout<<charArray[i]<<endl;
    }

    return 0;
}