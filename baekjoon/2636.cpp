/**
 * 문제 제목 : 치즈
 * 문제 링크 : https://www.acmicpc.net/problem/2636
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
vector<pair<int, int>> removeCheeses;
int terrain[100][100];
bool visited[100][100];
int totalCheeseNum;
int prevCheeseNum;

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (visited[ny][nx]) continue;
        if (terrain[ny][nx] == 1) {
            removeCheeses.push_back({ny, nx});
            visited[ny][nx] = true;
            continue;
        }
        dfs(ny, nx);
    }
}

int solve() {
    // 처음 가장자리 탐색
    for (int i = 0; i < N; i++) {
        if (!visited[i][0])     dfs(i, 0);
        if (!visited[i][M-1])   dfs(i, M - 1);
    }
    if (totalCheeseNum <= 0) return 0;
    int ret = 0;
    while (totalCheeseNum > 0) {
        ++ret;
        vector<pair<int, int>> removeCheesesCopy(removeCheeses);
        removeCheeses.clear();
        for (const pair<int, int>& removeCheese : removeCheesesCopy) {
            totalCheeseNum -= 1;
            dfs(removeCheese.first, removeCheese.second);
        }
        prevCheeseNum = removeCheesesCopy.size();
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> terrain[i][j];
            if (terrain[i][j] == 1) totalCheeseNum += 1;
        } 
    }
    int ret = solve();
    cout << ret << "\n";
    cout << prevCheeseNum << "\n";
    return 0;
}