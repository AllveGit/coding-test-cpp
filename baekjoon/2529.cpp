/**
 * 문제 제목 : 부등호
 * 문제 링크 : https://www.acmicpc.net/problem/2529
 * 
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
int k;
char cs[9];
vector<int> vec;
long long max_ret = -1;
string max_ret_str;
long long min_ret = 9999999999;
string min_ret_str;
bool oper(char a, int b, int c) {
    if (a == '<') return b < c;
    else          return b > c;
}
void solve(int depth)
{
    if (depth >= 2 && !oper(cs[depth-2], vec[depth-2], vec[depth-1])) return;
    if (depth == k + 1)
    {
        string s;
        s.resize(k + 1);
        for (int i = 0; i < k + 1; i++) s[i] = '0' + vec[i];
        long long ret = atoll(s.c_str());
        if (min_ret > ret) { min_ret = ret; min_ret_str = s; }
        if (max_ret < ret) { max_ret = ret; max_ret_str = s; }
        return;
    }
    for (int i = depth; i < 10; i++) {
        swap(vec[i], vec[depth]);
        solve(depth + 1);
        swap(vec[i], vec[depth]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++) cin >> cs[i];
    for (int i = 0; i < 10; i++) vec.push_back(i);
    solve(0);
    cout << max_ret_str << '\n';
    cout << min_ret_str << '\n';
}