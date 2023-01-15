/**
 * 문제 제목 : 오큰수
 * 문제 링크 : https://www.acmicpc.net/problem/17298
 * 
 * 크기가 N인 수열 A = A1, A2, ..., AN이 있다.
 * 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
 * Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
 * 그러한 수가 없는 경우에 오큰수는 -1이다.
 * 예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다.
 * A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.
 */

#include <bits/stdc++.h>
using namespace std;
int N, num;
int NGE[1000001];
stack<pair<int, int>> pending;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    fill(&NGE[0], &NGE[0] + 1000001, -1);
    for (int i = 0; i < N; i++) {
        cin >> num;
        while (pending.size() && pending.top().second < num) {
            NGE[pending.top().first] = num;
            pending.pop();
        }
        pending.push({ i, num });
    }
    for (int i = 0; i < N; i++) {
        cout << NGE[i] << " ";
    }
    return 0;
}