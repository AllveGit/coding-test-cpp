/**
 * 문제 제목 : 일곱 난쟁이
 * 문제 링크 : https://www.acmicpc.net/problem/2309
 *
 * 왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
 * 아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
 * 아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int dwarfHeights[9];

int dwarfNum = 9;
int selectNum = 7;

bool FindDwarf(int InStart, vector<int>& InVec)
{   
    if (InVec.size() == selectNum)
    {
        int sum = accumulate(InVec.begin(), InVec.end(), 0);
        return sum == 100;
    }

    for (int i = InStart + 1; i < dwarfNum; i++)
    {
        InVec.push_back(dwarfHeights[i]);

        bool bSuccessFind = FindDwarf(i, InVec);
        if (bSuccessFind)
        {
            return true;
        }

        InVec.pop_back();
    }

    return false;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> dwarfHeights[i];
    }

    vector<int> dwarfCombination;
    bool bSuccessFindDwarf = FindDwarf(-1, dwarfCombination);
    if (bSuccessFindDwarf)
    {
        sort(dwarfCombination.begin(), dwarfCombination.end());

        for (int dwarfHeight : dwarfCombination)
        {
            cout << dwarfHeight << "\n";
        }
    }

    return 0;
}