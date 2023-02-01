/**
 * 문제 제목 : 성곽
 * 문제 링크 : https://www.acmicpc.net/problem/2234
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
struct wallInfo {
    int y;
    int x;
    int wallIdx;
};
int m, n, ret1 = 0, ret2 = -1, ret3 = -1;
bool visited[55][55];
int wall[55][55];
vector<wallInfo> wallLists;
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
vector<int> dw = {(1 << 1), (1 << 2), (1 << 3), (1 << 0)};
int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        if (wall[y][x] & dw[i]) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
void solve() {
    for (int idx = 0; idx < wallLists.size() + 1; idx++) {
        if (idx != 0) {
            fill(&visited[0][0], &visited[0][0] + 55 * 55, 0);
            wallInfo info = wallLists[idx-1];
            wall[info.y][info.x] ^= dw[info.wallIdx];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                int area = dfs(i, j);
                if (idx == 0) {
                    ++ret1;
                    if (ret2 < area) ret2 = area;
                }
                if (ret3 < area) ret3 = area;
            }
        }
        if (idx != 0) {
            wallInfo info = wallLists[idx-1];
            wall[info.y][info.x] ^= dw[info.wallIdx];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> wall[i][j];
            for (int w = 0; w < 4; w++) {
                if (wall[i][j] & dw[w]) wallLists.push_back({i, j, w});
            }
        }
    }
    solve();
    cout << ret1 << '\n';
    cout << ret2 << '\n';
    cout << ret3 << '\n';
    return 0;
}