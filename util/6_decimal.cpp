#include <bits/stdc++.h>
using namespace std;

// 소수가 아닌 것들을 거른 값들을 캐싱해서 소수를 구하는 방법 (에라토스테네스의 체)
bool check[1000] = { 0 };
vector<int> era(int InMaxN)
{
    vector<int> v;
    for (int i = 2; i <= InMaxN; i++) 
    {
        if (check[i] == 1)
        {
            continue;
        }

        for (int j = i * 2; j <= InMaxN; j += i)
        {
            check[j] = 1;
        }
    }

    for (int i = 2; i <= InMaxN; i++)
    {
        if (check[i] == 1)
        {
            continue;
        }

        v.push_back(i);
    }
    return v;
}

// 배열의 크기가 너무 커지면 이 방법을 사용해야 함
bool CheckDecimal(int n)
{
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 2; i * i <=n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    vector<int> results1 = era(20);
    for (int result : results1)
    {
        cout << result << "\n";
    }

    for (int i = 1; i <= 20; i++)
    {
        if (CheckDecimal(i))
        {
            cout << i << "\n";
        }
    }
}