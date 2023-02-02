/**
 * 문제 제목 : 집합
 * 문제 링크 : https://www.acmicpc.net/problem/11723
 * 
 * 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
 * add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
 * remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
 * check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
 * toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
 * all: S를 {1, 2, ..., 20} 으로 바꾼다.
 * empty: S를 공집합으로 바꾼다. 
 */

#include <bits/stdc++.h>
using namespace std;
int m, n, ret;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s != "all" && s != "empty") cin >> n;
        int bitMask = (1 << n);
        if (s == "add")         ret |= bitMask;
        else if (s == "remove") ret &= ~bitMask;
        else if (s == "toggle") ret ^= bitMask;
        else if (s == "all")    ret = (1 << 21) - 1;
        else if (s == "empty")  ret = 0;
        else                    cout << ((ret & bitMask) ? 1 : 0) << '\n';
    }
    return 0;
}