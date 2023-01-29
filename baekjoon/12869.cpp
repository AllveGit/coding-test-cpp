/**
 * 문제 제목 : 뮤탈리스크
 * 문제 링크 : https://www.acmicpc.net/problem/12869
 * 
 * 수빈이는 강호와 함께 스타크래프트 게임을 하고 있다.
 * 수빈이는 뮤탈리스크 1개가 남아있고, 강호는 SCV N개가 남아있다.
 * 각각의 SCV는 남아있는 체력이 주어져있으며, 뮤탈리스크를 공격할 수는 없다.
 * 즉, 이 게임은 수빈이가 이겼다는 것이다.
 * 뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.
 *      첫 번째로 공격받는 SCV는 체력 9를 잃는다.
 *      두 번째로 공격받는 SCV는 체력 3을 잃는다.
 *      세 번째로 공격받는 SCV는 체력 1을 잃는다.
 * SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다.
 * 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.
 * 남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
struct TestRet {
    int hp1, hp2, hp3;
};
int damage[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};
int HPs[3];
int Visited[61][61][61];
int N;
queue<TestRet> Tests;
int solve(int hp1, int hp2, int hp3)
{
    int thp1, thp2, thp3;
    Visited[hp1][hp2][hp3] = 1;
    Tests.push({ hp1, hp2, hp3 });
    while (Tests.size())
    {
        thp1 = Tests.front().hp1;
        thp2 = Tests.front().hp2;
        thp3 = Tests.front().hp3;
        Tests.pop();
        for (int i = 0; i < 6; i++)
        {
            int nhp1 = max(0, thp1 - damage[i][0]);
            int nhp2 = max(0, thp2 - damage[i][1]);
            int nhp3 = max(0, thp3 - damage[i][2]);
            if (Visited[nhp1][nhp2][nhp3]) continue;
            Visited[nhp1][nhp2][nhp3] = Visited[thp1][thp2][thp3] + 1;
            Tests.push({ nhp1, nhp2, nhp3 });
        }
    }
    return Visited[0][0][0] - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> HPs[i];
    cout << solve(HPs[0], HPs[1], HPs[2]);
    return 0;
}