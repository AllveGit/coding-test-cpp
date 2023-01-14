/**
 * 문제 제목 : 교수가 된 현우
 * 문제 링크 : https://www.acmicpc.net/problem/3474
 *
 * 알고리즘의 킹갓제너럴엠퍼러마제스티충무공알고리즘마스터 현우가 교수로 취임하였다!
 * 그러나 학생들에게 크나큰 기대를 품고 첫 수업에 들어갔던 현우는 아무도 외판원 순회 문제(Traveling Salesman Problem, TSP)를 풀지 못하는 것을 보고 낙심하였다.
 * 그 와중에 학생 남규는 TSP를 완전탐색으로 풀려고 하였고, 현우는 그걸 보고 경악을 금치 못한다.
 * 왜냐면 TSP를 완전탐색으로 풀려면 O(N!)의 시간이 소모되는데, 이는 경악을 금치 못할 시간이기 때문이다.
 * 그러나 남규는 O(N!)이 왜 큰지도 잘 모른다.
 * 그래서 현우는 더더욱 경악을 금치 못하고, N!이 얼마나 큰지 대략적으로나마 알려주기 위해, 자연수 N이 주어지면 N!의 오른쪽 끝에 있는 0의 개수를 알려주기로 하였다.
 * 그러나 현우는 경악을 금치 못하여 지금 코딩을 할 수 없는 상황이다. 여러분이 현우를 대신하여 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

long long T;
long long Value; 

long long calc(long long value) {
    long long modValue = value / 5;
    if (modValue == 0) return 0;
    if (modValue == 1) return 1;
    return modValue + calc(modValue);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> Value;
        long long ret = calc(Value);
        cout << ret << "\n";
    }
    return 0;
}