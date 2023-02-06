/**
 * 문제 제목 : 큰수 A+B(@)
 * 문제 링크 : https://www.acmicpc.net/problem/14405
 *
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
string a, b, ret;
int aSize, bSize;
int aCnt = 0, bCnt = 0, up = 0;
int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    aSize = a.size(), bSize = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (aCnt < aSize || bCnt < bSize) {
        int curA = 0, curB = 0, calc = 0;
        if (aCnt < aSize) {
            curA = a[aCnt] - '0';
            ++aCnt;
        }
        if (bCnt < bSize) {
            curB = b[bCnt] - '0';
            ++bCnt;
        }
        calc = curA + curB + up;
        up = 0;
        if (calc >= 10) {
            up = 1;
            calc -= 10;
        }
        ret += (char)calc + '0';
    }
    if (up == 1) ret += '1';
    reverse(ret.begin(), ret.end());
    cout << ret;
    return 0;
}