/**
 * 문제 제목 : 안전 영역
 * 문제 링크 : https://www.acmicpc.net/problem/2468
 * 
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;

int N;
int maxheight = 0;
int terrain[101][101];
bool visited[101][101];
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

void dfs(int y, int x, int h) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || terrain[ny][nx] <= h) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx, h);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int height;
            cin >> height;
            terrain[i][j] = height;
            if (maxheight < height) maxheight = height;
        }
    }

    int res = 1;
    for (int h = 1; h < maxheight; h++) {
        memset(visited, 0, sizeof(bool) * 101 * 101);
        int ret = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[y][x] && terrain[y][x] > h) {
                    dfs(y, x, h);
                    ++ret;
                }
            }
        }
        res = max(res, ret);
    }

    cout << res << "\n";

    return 0;
}