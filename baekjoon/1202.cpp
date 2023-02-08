/**
 * 문제 제목 : 보석 도둑
 * 문제 링크 : https://www.acmicpc.net/problem/1202
 *
 * 세계적인 도둑 상덕이는 보석점을 털기로 결심했다.
 * 상덕이가 털 보석점에는 보석이 총 N개 있다. 
 * 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 
 * 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 
 * 가방에는 최대 한 개의 보석만 넣을 수 있다.
 * 상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, m, v, c, ret;
vector<pair<ll, ll>> jewels;
vector<ll> bags;
priority_queue<ll> pq;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewels.push_back({ m, v });
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        bags.push_back(c);
    }
    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && jewels[j].first <= bags[i]) pq.push(jewels[j++].second);
        if (pq.size()) { ret += pq.top(); pq.pop(); }
    }
    cout << ret << "\n";
    return 0;
}