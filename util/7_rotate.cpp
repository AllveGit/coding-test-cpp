#include <bits/stdc++.h>
using namespace std;

vector<int> v1;
vector<int> v2;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i);
    }

    // 시계 방향 회전
    // (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) -> (10, 1, 2, 3, 4, 5, 6, 7, 8, 9)
    rotate(v1.begin(), v1.begin() + v1.size() - 1, v1.end());

    for (int elem : v1)
    {
        cout << elem << " ";
    }
    cout << "\n";

    // 반 시계 방향 회전
    // (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) -> (4, 5, 6, 7, 8, 9, 10, 1, 2, 3)
    rotate(v2.begin(), v2.begin() + 3, v2.end());

    for (int elem : v2)
    {
        cout << elem << " ";
    }
    cout << "\n";

    return 0;
}