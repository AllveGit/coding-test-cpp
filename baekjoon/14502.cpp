/**
 * 문제 제목 : 연구소
 * 문제 링크 : https://www.acmicpc.net/problem/14502
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
vector<pair<int, int>> virusLists;
vector<pair<int, int>> wallableLists;
int terrain[10][10];
bool visited[10][10];

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || terrain[ny][nx] != 0) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int solve() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (const pair<int, int>& virus : virusLists) {
        dfs(virus.first, virus.second);
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (terrain[i][j] == 0 && !visited[i][j]) ++ret;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int elem;
            cin >> elem;
            if (elem == 0) wallableLists.push_back({y, x});
            else if (elem == 2) virusLists.push_back({y, x});
            terrain[y][x] = elem;
        }
    }

    int ret = 0;
    for (int i = 0; i < wallableLists.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                terrain[wallableLists[i].first][wallableLists[i].second] = 1;
                terrain[wallableLists[j].first][wallableLists[j].second] = 1;
                terrain[wallableLists[k].first][wallableLists[k].second] = 1;
                ret = max(ret, solve());
                terrain[wallableLists[i].first][wallableLists[i].second] = 0;
                terrain[wallableLists[j].first][wallableLists[j].second] = 0;
                terrain[wallableLists[k].first][wallableLists[k].second] = 0;
            }
        }
    }
    cout << ret;
    return 0;
}