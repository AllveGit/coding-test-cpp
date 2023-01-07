/**
 * 문제 제목 : 곱셈
 * 문제 링크 : https://www.acmicpc.net/problem/1629
 * 
 * 자연수 A를 B번 곱한 수를 알고 싶다. 
 * 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long calculate(long long a, long long b) {
    if (b == 1) 
        return a % c;

    long long ret = calculate(a, b / 2);
    ret = (ret * ret) % c;
    if (b % 2) ret = (ret * a) % c;
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    cout << calculate(a, b);

    return 0;
}