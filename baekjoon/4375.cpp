/**
 * 문제 제목 : 1
 * 문제 링크 : https://www.acmicpc.net/problem/4375
 * 
 * 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    while (scanf("%d", &N) != EOF) {
        int cnt = 1, ret = 1;
        while (true) {
            if (cnt % N == 0) {
                printf("%d\n", ret);
                break;
            }
            cnt = (cnt * 10) + 1;
            cnt %= N;
            ++ret;
        }
    }
    return 0;
}