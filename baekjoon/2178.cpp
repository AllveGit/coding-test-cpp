/**
 * 문제 제목 : 미로 탐색
 * 문제 링크 : https://www.acmicpc.net/problem/2178
 * 
 * N×M크기의 배열로 표현되는 미로가 있다.
 * 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
 * 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
 * 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
 * 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> directionY = {-1, 0, 1, 0};
vector<int> directionX = {0, 1, 0, -1};
queue<pair<int, int>> q;

bool terrain[101][101];
int visited[101][101];
int cy, cx;
int ny, nx;

void go(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()) {
        tie(cy, cx) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            ny = cy + directionY[i];
            nx = cx + directionX[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || !terrain[ny][nx]) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            scanf(" %c", &c);
            terrain[i][j] = (bool)(c - '0');
        }
    }

    go(0, 0);

    cout << visited[N - 1][M - 1] << "\n";

    return 0;
}