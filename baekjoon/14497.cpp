/**
 * 문제 제목 : 주난의 난
 * 문제 링크 : https://www.acmicpc.net/problem/14497
 * 
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
char terrain[301][301];
bool visited[301][301];
pair<int, int> start;
pair<int, int> choco;
vector<pair<int, int>> friends;
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
int dfs(int y, int x) {
    visited[y][x] = true;
    if (terrain[y][x] == '#') return 1;
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        if (terrain[ny][nx] == '1') {
            terrain[ny][nx] = '0';
            visited[ny][nx] = true;
        }
        else {
            ret += dfs(ny, nx);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> start.first >> start.second >> choco.first >> choco.second;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++) {
            char c = s[j];
            if (c == '*')       start = { i, j };
            else if (c == '#')  choco = { i, j };
            else if (c == '1')  friends.push_back({ i,j });
            terrain[i][j] = c;
        }
    }
    int cnt = 1;
    while (!dfs(start.first, start.second)) {
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        ++cnt;
    }
    cout << cnt;
    return 0;
}