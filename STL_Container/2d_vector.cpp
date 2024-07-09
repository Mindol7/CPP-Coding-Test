#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v1;

int rows = 3;
int cols = 4;

vector<vector<int>> v2(rows, vector<int>(cols));

int vals = 9;
vector<vector<int>> v3(rows, vector<int>(cols, vals));

vector<vector<int>> v4 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
