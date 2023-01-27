/**
 * 문제 제목 : 치킨 배달
 * 문제 링크 : https://www.acmicpc.net/problem/15686
 * 
 * 크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 
 * 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 
 * 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. 
 * r과 c는 1부터 시작한다.
 * 이 도시에 사는 사람들은 치킨을 매우 좋아한다.
 * 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다.
 * 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다.
 * 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다.
 * 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.
 * 임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.
 * 예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;
int MinDistance = 100000;
int Terrain[51][51];
vector<pair<int,int>> Homes;
vector<pair<int,int>> Chickens;
vector<pair<int,int>> Tests;
int CalcDistance()
{
    int ret = 0;
    for (const auto& home : Homes) {
        int chickenDist = 100000;
        for (const auto& test : Tests) {
            int dist = abs(home.first - test.first) + abs(home.second - test.second);
            if (dist < chickenDist) chickenDist = dist;
        }
        ret += chickenDist;
    }
    return ret;
}
void Solve(int InStart)
{
    if (Tests.size() == M)
    {
        int distance = CalcDistance();
        if (distance < MinDistance) MinDistance = distance;
        return;
    }

    for (int i = InStart + 1; i < Chickens.size(); i++)
    {
        Tests.push_back(Chickens[i]);
        Solve(i);
        Tests.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int value;
            cin >> value;
            if (value == 1)     Homes.push_back({i, j});
            else if(value == 2) Chickens.push_back({i, j});
            Terrain[i][j] = value;
        }
    }
    Solve(-1);
    cout << MinDistance;
    return 0;
}