#include <bits/stdc++.h>
using namespace std;

// 2차원 배열 왼쪽으로 90도 회전
void RotateLeft90(vector<vector<int>> &key){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = key[j][m - i - 1];
        }
    }
    key = temp;
    return;
}

// 2차원 배열 오른쪽으로 90도 회전
void RotateRight90(vector<vector<int>> &key){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = key[m - j - 1][i];
        }
    }
    key = temp;
    return;
}

int main()
{
    
    return 0;
}