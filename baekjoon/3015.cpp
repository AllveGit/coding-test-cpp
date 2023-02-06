/**
 * 문제 제목 : 오아시스 재결합
 * 문제 링크 : https://www.acmicpc.net/problem/3015
 *
 * 오아시스의 재결합 공연에 N명이 한 줄로 서서 기다리고 있다.
 * 이 역사적인 순간을 맞이하기 위해 줄에서서 기다리고 있던 백준이는 갑자기 자기가 볼 수 있는 사람의 수가 궁금해 졌다.
 * 두 사람 A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.
 * 줄에 서있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, temp;
stack<pair<ll, ll>> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int cnt = 1;
        while (s.size() && s.top().first <= temp) {
            ret += s.top().second;
            if (s.top().first == temp) {
                cnt = s.top().second + 1;
            } else {
                cnt = 1;
            }
            s.pop();
        }
        if (s.size()) ++ret;
        s.push({temp, cnt});
    }
    cout << ret << '\n';
    return 0;
}