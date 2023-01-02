#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};

void print(vector<int>& InVec)
{
    for (const int elem : InVec)
    {
        cout << elem << " ";
    }

    cout << "\n";
}

// 재귀로 조합 만드는 법
void combi(int InStart, vector<int>& InVec)
{
    if (InVec.size() == k)
    {
        print(InVec);
        return;
    }

    for (int i = InStart + 1; i < n; i++)
    {
        InVec.push_back(i);
        combi(i, InVec);
        InVec.pop_back();
    }
}

int main()
{
    vector<int> testVec;
    combi(-1, testVec);
    return 0;
}