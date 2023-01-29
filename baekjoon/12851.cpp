/**
 * 문제 제목 : 숨바꼭질2
 * 문제 링크 : https://www.acmicpc.net/problem/12851
 * 
 * 수빈이는 동생과 숨바꼭질을 하고 있다.
 * 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
 * 수빈이는 걷거나 순간이동을 할 수 있다.
 * 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
 * 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
 * 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
int N, K;
pair<int, int> visited[100001];
queue<int> q;
void solve(int x) {
    int cx;
    int nx1, nx2, nx3;
    int nextDepth;
    visited[x] = { 1, 1 };
    q.push(x);
    while (q.size()) {
        cx = q.front();
        q.pop();
        nx1 = cx * 2;
        nx2 = cx + 1;
        nx3 = cx - 1;
        nextDepth = visited[cx].first + 1;
        if (nx1 <= 100000) {
            if (!visited[nx1].first) {
                visited[nx1] = { nextDepth, 1 };
                q.push(nx1);
            }
            else if (visited[nx1].first == nextDepth) {
                visited[nx1].second += 1;
                q.push(nx1);
            }
        }
        if (nx2 <= 100000) {
            if (!visited[nx2].first) {
                visited[nx2] = { nextDepth, 1 };
                q.push(nx2);
            }
            else if (visited[nx2].first == nextDepth) {
                visited[nx2].second += 1;
                q.push(nx2);
            }
        }
        if (nx3 >= 0) {
            if (!visited[nx3].first) {
                visited[nx3] = { nextDepth, 1 };
                q.push(nx3);
            }
            else if (visited[nx3].first == nextDepth) {
                visited[nx3].second += 1;
                q.push(nx3);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    solve(N);
    cout << visited[K].first - 1 << "\n";
    cout << visited[K].second << "\n";
    return 0;
}