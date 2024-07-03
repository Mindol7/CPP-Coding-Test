#include <iostream>
using namespace std;

int main(){
    double d = 2.5;
    float f = 1.5f;
    int i = 65;

    cout<<sizeof(d)<<endl;
    cout<<sizeof(f)<<endl;
    cout<<sizeof(i)<<endl;
    cout<<d<<" "<<f<<endl;
    cout<<d+f<<endl;
    cout<<d-f<<endl;
    cout<<d*f<<endl;
    cout<<d/f<<endl;
    
    return 0;
}