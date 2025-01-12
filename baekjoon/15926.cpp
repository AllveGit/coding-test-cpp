/**
 * 문제 제목 : 현욱은 괄호왕이야!!
 * 문제 링크 : https://www.acmicpc.net/problem/15926
 *
 * 여는 괄호 ‘(’와 닫는 괄호 ‘)’로 구성된 문자열에서 아래의 조건을 만족하는 문자열을 올바른 괄호 문자열이라고 부른다.
 *      () 는 올바른 괄호 문자열이다.
 *      어떤 문자열 x가 올바른 괄호 문자열이라면, (x)도 올바른 괄호 문자열이다.
 *      어떤 문자열 x와 y가 올바른 괄호 문자열이라면, xy도 올바른 괄호 문자열이다.
 * 현욱은 친구로부터 생일 선물로 굉장히 긴 괄호 문자열을 받았다(도대체 왜 이런 걸 선물하는걸까?).
 * 하지만 현욱은 올바른 괄호 문자열이 아니면 굉장히 싫어하기 때문에, 받은 괄호 문자열에서 연속한 일부분을 잘라서 올바른 괄호 문자열을 만들려고 한다. 
 * 그리고 이왕이면 긴 문자열이 좋으니 현욱은 부분 구간을 최대한 길게 잘라내려고 한다.
 * 현욱을 도와 주어진 괄호 문자열에서 위의 조건을 만족하는 가장 긴 부분 문자열의 길이를 계산하는 프로그램을 작성해보자.
 */

#include <bits/stdc++.h>
using namespace std;
int n, ret, cnt, d[200001];
string s;
stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        else if(stk.size()) {
            d[i] = d[stk.top()] = 1;
            stk.pop();
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i]) {
            ++cnt;
            ret = max(ret, cnt);
        }
        else cnt = 0;
    }
    cout << ret << '\n';
}