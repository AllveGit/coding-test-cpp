/**
 * 문제 제목 : 인구 이동
 * 문제 링크 : https://www.acmicpc.net/problem/16234
 * 
 * N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다.
 * 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다.
 * 인접한 나라 사이에는 국경선이 존재한다.
 * 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.
 * 오늘부터 인구 이동이 시작되는 날이다.
 * 인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.
 *      국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
 *      위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
 *      국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
 *      연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
 *      연합을 해체하고, 모든 국경선을 닫는다.
 * 각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
int N, L, R;
int terrain[51][51];
bool visited[51][51];
vector<pair<int, int>> unions;
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
int dfs(int y, int x) {
    int ret = terrain[y][x];
    visited[y][x] = true;
    unions.push_back({ y, x });
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
        int diff = abs(terrain[y][x] - terrain[ny][nx]);
        if (diff < L || diff > R) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int solve() {
    int ret = 0;
    while (true) {
        bool bMoved = false;
        memset(visited, 0, 51 * 51 * sizeof(bool));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                unions.clear();
                int unionPeople = dfs(i, j);
                bool bCurMoved = unions.size() > 1;
                if (bCurMoved) {
                    int averPeople = unionPeople / unions.size();
                    for (auto na : unions) {
                        terrain[na.first][na.second] = averPeople;
                    }
                    bMoved = true;
                }
            }
        }
        if (!bMoved) break;
        ++ret;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
	    for (int j = 0; j < N; j++) {
            cin >> terrain[i][j];
	    }
    }
    cout << solve();
    return 0;
}