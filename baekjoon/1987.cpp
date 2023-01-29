/**
 * 문제 제목 : 알파벳
 * 문제 링크 : https://www.acmicpc.net/problem/1987
 * 
 * 세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다.
 * 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
 * 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.
 * 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
 * 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오.
 * 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
 */

#include <bits/stdc++.h>
using namespace std;
int r, c;
string s;
char terrain[21][21];
bool visited[26];
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
int dfs(int y, int x, int depth) {
    int ret = depth;
    visited[terrain[y][x]-'A'] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[terrain[ny][nx]-'A']) continue;
        ret = max(ret, dfs(ny, nx, depth + 1));
    }
    visited[terrain[y][x]-'A'] = false;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    cin.ignore();
    for (int i = 0; i < r; i++) {
        getline(cin, s);
        for (int j = 0; j < c; j++) {
            terrain[i][j] = s[j];
        }
    }
    set<int> path;
    cout << dfs(0, 0, 1);
    return 0;
}