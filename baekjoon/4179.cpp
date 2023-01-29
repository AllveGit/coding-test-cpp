/**
 * 문제 제목 : 불!
 * 문제 링크 : https://www.acmicpc.net/problem/4179
 *
 * 지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
 * 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
 * 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다. 
 * 불은 각 지점에서 네 방향으로 확산된다. 
 * 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다. 
 * 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
 */

#include <bits/stdc++.h>
using namespace std;
int R, C;
int ExitTime = 10000000;
bool bExited = false;
string s;
char terrain[1001][1001];
int visited[1001][1001];
int fired[1001][1001];
pair<int, int> startPlayer;
vector<pair<int, int>> startFires;
queue<pair<int, int>> q;
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
void simulateFire() {
    int fy, fx;
    int cy, cx;
    int ny, nx;
    for (const auto& startFire : startFires) {
        tie(fy, fx) = startFire;
        q.push({fy, fx});
        fired[fy][fx] = 1;
    }
    while(q.size()) {
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || fired[ny][nx] || terrain[ny][nx] == '#' || terrain[ny][nx] == 'F') continue;
            fired[ny][nx] = fired[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}
void simulateExit() {
    int py, px;
    int cy, cx;
    int ny, nx;
    tie(py, px) = startPlayer;
    q.push({startPlayer.first, startPlayer.second});
    visited[py][px] = 1;
    while(q.size()) {
        tie(cy, cx) = q.front();
        q.pop();
        if (cy == 0 || cy == R-1 || cx == 0 || cx == C-1) {
            bExited = true;
            if (ExitTime > visited[cy][cx]) ExitTime = visited[cy][cx];
            continue;
        } 
        for (int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || terrain[ny][nx] != '.') continue;
            if (fired[ny][nx] != 0 && fired[ny][nx] <= visited[cy][cx] + 1)                          continue; 
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    cin.ignore();
    for (int i = 0; i < R; i++) {
        getline(cin, s);
        for (int j = 0; j < C; j++) {
            char c = s[j];
            terrain[i][j] = c;
            if (c == 'J')       startPlayer = {i, j};
            else if (c == 'F')  startFires.push_back({i, j});
        }
    }
    simulateFire();
    simulateExit();
    if (!bExited) cout << "IMPOSSIBLE";
    else          cout << ExitTime;
    return 0;
}