/**
 * 문제 제목 : 효율적인 해킹
 * 문제 링크 : https://www.acmicpc.net/problem/1325
 * 
 * 해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다.
 * 이 회사는 N개의 컴퓨터로 이루어져 있다.
 * 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
 * 이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
 * 이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
int N, M;
int a, b;
vector<int> connects[10001];
bool visited[10001];
int dfs(int index) {
    if (visited[index]) return 0;
    visited[index] = true;
    int ret = 1;
    for (int connect : connects[index]) {
        ret += dfs(connect);
    }
    return ret;
}
vector<int> solve() {
    vector<int> ret;
    int maxConnectNums = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[0] + 10001, 0);
        int connectNums = dfs(i);
        if (maxConnectNums < connectNums) {
            ret.clear();
            ret.push_back(i);
            maxConnectNums = connectNums;
        } 
        else if (maxConnectNums == connectNums) {
            ret.push_back(i);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        connects[b].push_back(a); 
    }
    vector<int> ret = solve();
    for (int i : ret) {
        cout << i << " ";
    }
    return 0;
}