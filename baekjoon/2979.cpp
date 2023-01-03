/*
 * 문제 : 트럭 주차
 *
 * 상근이는 트럭을 총 세 대 가지고 있다. 오늘은 트럭을 주차하는데 비용이 얼마나 필요한지 알아보려고 한다.
 * 상근이가 이용하는 주차장은 주차하는 트럭의 수에 따라서 주차 요금을 할인해 준다.
 * 트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 두 대를 주차할 때는 1분에 한 대당 B원, 세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.
 * A, B, C가 주어지고, 상근이의 트럭이 주차장에 주차된 시간이 주어졌을 때, 주차 요금으로 얼마를 내야 하는지 구하는 프로그램을 작성하시오.
 * 
 * 문제 링크 : https://www.acmicpc.net/problem/2979
 */

#include <bits/stdc++.h>
using namespace std;

const int TRUCK_NUM = 3;

int price[3];
int start[3];
int finish[3];

int main()
{
    for (int i = 0; i < TRUCK_NUM; i++)
    {
        cin >> price[i];
        price[i] = price[i] * (i + 1);
    }

    int minStart = 200;
    int maxFinish = 0;
    for (int i = 0; i < TRUCK_NUM; i++)
    {
        cin >> start[i] >> finish[i];

        if (minStart > start[i])
            minStart = start[i];

        if (maxFinish < finish[i])
            maxFinish = finish[i];
    }

    int totalPrice = 0;
    int parkCnt = 0;
    for (int i = minStart; i <= maxFinish; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (i == start[j]) 
                ++parkCnt;

            if (i == finish[j]) 
                --parkCnt;
        }
        
        if (parkCnt == 0)
            continue;

        totalPrice += price[parkCnt - 1];
    }

    cout << totalPrice;

    return 0;
}