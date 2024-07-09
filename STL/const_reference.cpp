#include <iostream>

using namespace std;

void modify(int value){
    value = 10;
    cout<<"Address : "<<&value<<endl;
    cout<<"Value : "<<value<<endl;
}

int main(){
    int value = 5;
    cout<<"Address : "<<&value<<endl;
    cout<<"Value : "<<value<<endl;
    modify(value);
    cout<<"Value : "<<value<<endl;

    return 0;
}
