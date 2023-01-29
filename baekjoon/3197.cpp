/**
 * 문제 제목 : 백조의 호수
 * 문제 링크 : https://www.acmicpc.net/problem/3197
 * 
 * 두 마리의 백조가 호수에서 살고 있었다. 
 * 그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.
 * 호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.
 * 호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 
 * 두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.
 * 백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.
 * 며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
int r, c;
string s;
int startY = -1, startX = -1, endY = -1, endX = -1;
char terrain[1501][1501];
bool startVisited[1501][1501];
bool waterVisited[1501][1501];
vector<pair<int, int>> wallList;
vector<pair<int, int>> waterList;
vector<pair<int, int>> startList;
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
int dfsStart(int y, int x, bool bInit)
{
    startVisited[y][x] = true;
    if (!bInit && terrain[y][x] == 'L') return 1;
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || startVisited[ny][nx]) continue;
        if (terrain[ny][nx] == 'X') { startList.push_back({ ny, nx }); continue; }
        ret += dfsStart(ny, nx, false);
    }
    return ret;
}
void checkWall(int y, int x) {
    waterVisited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || waterVisited[ny][nx]) continue;
        if (terrain[ny][nx] == 'X') { wallList.push_back({ ny, nx }); continue; }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    cin.ignore();
    for (int i = 0; i < r; i++) {
        getline(cin, s);
        for (int j = 0; j < c; j++) {
            char c = s[j];
            if (c == 'L') {
                if (startY == -1) { startY = i; startX = j; }
                else { endY = i; endX = j; }
            }
            if (c == '.' || c == 'L') { waterList.push_back({ i, j }); }
            terrain[i][j] = c;
        }
    }
    if (dfsStart(startY, startX, true)) { cout << 0; return 0; }
    int cnt = 1;
    while (true) {
        for (const auto& water : waterList) {
            if (waterVisited[water.first][water.second]) continue;
            checkWall(water.first, water.second);
        }
        waterList.clear();
        for (const auto& wall : wallList) {
            terrain[wall.first][wall.second] = '.';
            waterList.push_back({ wall.first, wall.second });
        }
        wallList.clear();
        vector<pair<int,int>> tempStartList = startList;
        startList.clear();
        bool bMeeted = false;
        for (const auto& start : tempStartList)
        {
            if (startVisited[start.first][start.second]) continue;
            if(!bMeeted) bMeeted = dfsStart(start.first, start.second, false);
        }
        if (bMeeted) break;
        ++cnt;
    }
    cout << cnt;
    return 0;
}