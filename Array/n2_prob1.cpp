#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void bubbleSort(vector<int> &v){
    for(size_t i = 0; i < v.size(); ++i){  
        for(size_t j = 0; j <v.size() -i - 1; ++j){ // 각 요소에 대해서 모든 뒤의 원소들과 비교
            if(v[j] > v[j + 1]){ 
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main(){
    vector<int> vec(30000);
    for(int i = 0; i < 30000; ++i){
        vec[i] = i + 1;
    }

    vector<int> vecForBubbleSort = vec;
    clock_t startBubbleSort = clock();
    bubbleSort(vecForBubbleSort);
    clock_t endBubbleSort = clock();
    double timeBubbleSort = double(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;

    vector<int> vecForStdSort = vec;
    clock_t startStdSort = clock();
    sort(vecForStdSort.begin(), vecForStdSort.end());
    clock_t endStdSort = clock();

    double timeStdSort = double(endStdSort - startStdSort) / CLOCKS_PER_SEC;

    cout<<"Bubble Sort Time : "<<timeBubbleSort<<endl;
    cout<<"STD Sort Time : "<<timeStdSort<<endl;
    
    return 0;
}