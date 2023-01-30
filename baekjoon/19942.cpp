/**
 * 문제 제목 : 다이어트
 * 문제 링크 : https://www.acmicpc.net/problem/19942
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
struct mat {
    int p;
    int f;
    int s;
    int v;
    int c;
};
const int INF = 987654321;
int n, mp, mf, ms, mv;
int tp, tf, ts, tv, tc;
int ret_cost = INF;
int ret_select = -1;
mat mats[15];
void go(int start, int num) {
    if (tp >= mp && tf >= mf && ts >= ms && tv >= mv) {
        if (ret_cost > tc) {
            ret_cost = tc;
            ret_select = num;
        }
        return;
    }
    for (int i = start; i < n; i++) {
        if (num & (1 << i)) continue;
        tp += mats[i].p; tf += mats[i].f; ts += mats[i].s; tv += mats[i].v; tc += mats[i].c;
        go(i + 1, num | (1 << i));
        tp -= mats[i].p; tf -= mats[i].f; ts -= mats[i].s; tv -= mats[i].v; tc -= mats[i].c;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> mats[i].p >> mats[i].f >> mats[i].s >> mats[i].v >> mats[i].c;
    }
    go(0, 0);
    if (ret_cost == INF) { cout << -1; }
    else {
        cout << ret_cost << '\n';
        for (int i = 0; i < n; i++) {
            if (ret_select & (1 << i)) cout << i + 1 << " ";
        }
    }
    return 0;
}