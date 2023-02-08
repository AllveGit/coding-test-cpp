/**
 * 문제 제목 : 두 수의 합
 * 문제 링크 : https://www.acmicpc.net/problem/3273
 * 
 * n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다.
 * ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다.
 * 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
int n, x, val, lo, hi, ret;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        a.push_back(val);
    }
    cin >> x;
    sort(a.begin(), a.end());
    lo = 0;
    hi = a.size() - 1;
    while (true) {
        if (lo == hi) break;
        int sum = a[lo] + a[hi];
        if (sum == x) { ++ret; ++lo; }
        else if (sum > x) { --hi; }
        else { ++lo; }
    }
    cout << ret;
    return 0;
}