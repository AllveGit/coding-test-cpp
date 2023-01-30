/**
 * 문제 제목 : 컴백홈
 * 문제 링크 : https://www.acmicpc.net/problem/14620
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
int r, c, k, startY, startX, endY, endX;
string s;
char terrain[6][6];
bool visited[6][6];
int ret[26];
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
void solve(int y, int x, int dist) {
    if (y == endY && x == endX) {
        ret[dist] += 1;
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
        solve(ny, nx, dist + 1);
    }
    visited[y][x] = false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> k;
    cin.ignore();
    for (int i = 0; i < r; i++) {
        getline(cin, s);
        for (int j = 0; j < c; j++) {
            char c = s[j];
            terrain[i][j] = c;
            if (c == 'T') visited[i][j] = true;
        }
    }
    startY = r-1; startX = 0; endY = 0; endX = c-1;
    solve(startY, startX, 1);
    cout << ret[k];
    return 0;
}