#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void PrintV(vector<int> &InV)
{
    for (int i = 0; i < InV.size(); i++)
    {
        cout << InV[i] << "";
    }
    cout << "\n";
}

void MakePermutation(int n, int r, int depth)
{
    if (r == depth)
    {
        PrintV(v);
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        MakePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        v.push_back(i);
    }

    // 함수로 순열 만드는 법 (C++만 지원)
    do {
        PrintV(v);
    } while(next_permutation(v.begin(), v.end()));

    // 재귀로 순열 만드는 법
    MakePermutation(3, 3, 0);

    return 0;
}