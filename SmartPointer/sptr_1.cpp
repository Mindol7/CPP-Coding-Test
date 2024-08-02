#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Cat{
    private:
        int mAge;
    public:
        Cat():mAge(0){
            cout<<"Cat constructor"<<endl;
        }
        ~Cat(){
            cout<<"Cat Destructor"<<endl;
        }
};

void foo(){
    cout<<"Foo Start"<<endl;
    vector<Cat> cats(5);
    cout<<"Foo End"<<endl;
}

int main(){

    cout<<"Scope Start"<<endl;
    foo();
    cout<<"Scope End"<<endl;
    return 0;
}