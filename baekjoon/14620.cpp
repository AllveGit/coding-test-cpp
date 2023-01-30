/**
 * 문제 제목 : 꽃길
 * 문제 링크 : https://www.acmicpc.net/problem/14620
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF;
int gold[10][10];
bool visited[10][10];
bool simulated[10][10];
vector<int> dy = { -1, 0, 1, 0 };
vector<int> dx = { 0, 1, 0, -1 };
void go(int y, int x, int cnt, int totalprice) {
    if (ret <= totalprice) return;
    if (cnt >= 3) {
        if (ret > totalprice) ret = totalprice;
        return;
    }
    for (int i = y; i < n - 1; i++) {
        for (int j = x; j < n - 1; j++) {
            if (visited[i][j] || visited[i-1][j] || visited[i][j+1] || visited[i+1][j] || visited[i][j-1]) continue;
            int price = gold[i][j] + gold[i-1][j] + gold[i][j+1] + gold[i+1][j] + gold[i][j-1];
            visited[i][j] = true; visited[i-1][j] = true; visited[i][j+1] = true; visited[i+1][j] = true; visited[i][j-1] = true;
            go(1, 1, cnt + 1, totalprice + price);
            visited[i][j] = false; visited[i-1][j] = false; visited[i][j+1] = false; visited[i+1][j] = false; visited[i][j-1] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gold[i][j];
        }
    }
    go(1, 1, 0, 0);
    cout << ret;
    return 0;
}