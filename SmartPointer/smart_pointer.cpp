#include <iostream>
#include <memory>

using namespace std;

class Cat{
    private:
        int mAge;
    public:
        Cat(int age):mAge(age){
            cout<<"Cat Constructor"<<endl;
        }
        ~Cat(){
            cout<<"Cat Destructor"<<endl;
        }
};

int main(){
    shared_ptr<Cat> catPtr = make_shared<Cat>(5);
    cout<<"Count : "<<catPtr.use_count()<<endl;
    shared_ptr<Cat> catPtr1 = catPtr;
    cout<<"Count : "<<catPtr.use_count()<<endl;

    return 0;
}