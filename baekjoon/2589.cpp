/**
 * 문제 제목 : 보물섬
 * 문제 링크 : https://www.acmicpc.net/problem/2589
 * 
 * 보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다.
 * 보물섬 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다.
 * 각 칸은 육지(L)나 바다(W)로 표시되어 있다.
 * r과 c는 1부터 시작한다.
 * 이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다.
 * 보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.
 * 육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안 된다.
 */
#include <bits/stdc++.h>
using namespace std;
int N, M;
char Terrain[51][51];
int visited[51][51];
int ret;
string s;
queue<pair<int, int>> q;
vector<pair<int, int>> lands;
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
int solve(int y, int x)
{
    memset(visited, 0, 51 * 51 * sizeof(int));
    int cy, cx;
    int ny, nx;
    int maxDist = 1;
    visited[y][x] = 1;
    q.push({ y, x });
    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || Terrain[ny][nx] == 'W') continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ ny, nx });
            if (maxDist < visited[ny][nx]) maxDist = visited[ny][nx];
        }
    }
    return maxDist;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for (int j = 0; j < M; j++) {
            const char c = s[j];
            Terrain[i][j] = c;
            if (c == 'L') lands.push_back({ i, j });
        }
    }
    for (auto land : lands) {
        int dist = solve(land.first, land.second);
        if (ret < dist) ret = dist;
    }
    cout << (ret - 1);
    return 0;
}