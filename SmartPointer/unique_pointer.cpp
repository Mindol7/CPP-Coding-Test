#include <iostream>
#include <memory>

using namespace std;
class Animal{};

class Cat : public Animal{
    private:
        int cAge;
    public:
        Cat(int age):cAge(age){
            cout<<"Cat Constructor"<<endl;
        }
        ~Cat(){
            cout<<"Cat Destructor"<<endl;
        }
};

class Dog : public Animal{};

class Zoo{
    private:
        unique_ptr<Animal> animal;
    public:
        Zoo(int n){
            if(n==1){
                animal = make_unique<Cat>(1);
            }
            else{
                animal = make_unique<Dog>();
            }
        }
};


int main(){


    return 0;
}