/**
 * 문제 제목 : tree
 * 문제 링크 : https://www.acmicpc.net/problem/13244
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b, start;
vector<int> lines[1001];
bool visited[1001];
int cnt;
bool dfs(int curIdx, int prevIdx) {
    visited[curIdx] = true;
    ++cnt;
    for (int line : lines[curIdx]) {
        if (line == prevIdx) continue;
        if (visited[line]) return false;
        if (!dfs(line, curIdx)) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (i == 0) { start = a; }
            lines[a].push_back(b); lines[b].push_back(a);
        }
        bool bTree = dfs(start, -1) && cnt == n;
        cout << (bTree ? "tree" : "graph") << '\n';
        cnt = 0;
        fill(&visited[0], &visited[0] + 1001, 0);
        for (int i = 0; i < 1001; i++) lines[i].clear();
    }
    return 0;
}