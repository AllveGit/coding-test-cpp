/**
 * 문제 제목 : 수학숙제
 * 문제 링크 : https://www.acmicpc.net/problem/2870
 * 
 * 상근이는 수학시간에 딴 짓을 하다가 선생님께 걸렸다. 
 * 선생님은 상근이에게 이번 주말동안 반성하라며 엄청난 숙제를 내주었다.
 * 선생님이 상근이에게 준 종이에는 숫자와 알파벳 소문자로 되어있는 글자가 N줄있다.
 * 상근이는 여기서 숫자를 모두 찾은 뒤, 이 숫자를 비내림차순으로 정리해야한다.
 * 숫자의 앞에 0이 있는 경우에는 정리하면서 생략할 수 있다.
 * 글자를 살펴보다가 숫자가 나오는 경우에는, 가능한 가장 큰 숫자를 찾아야 한다.
 * 예를 들어, 01a2b3456cde478에서 숫자를 찾으면 1, 2, 3456, 478이다.
 * 선생님이 준 종이의 내용이 주어졌을 때, 상근이의 숙제를 대신하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> results;

bool IsNumeric(char check) {
    return check >= '0' && check <= '9';
}

bool cmp(const string& a, const string& b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void CalcStr(string& OutStr) {
    while (true) {
        if (OutStr.size() && OutStr.front() == '0') OutStr.erase(OutStr.begin());
        else break;
    }
    if (OutStr.size() == 0) OutStr = '0';
    results.push_back(OutStr);
    OutStr = "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string substr;
    for (int i = 0; i < N; i++) {
        cin >> s;
        bool bFindingChar = true;
        for (int j = 0; j < s.size(); j++) {
            bool bIsNumeric = IsNumeric(s[j]);
            if (bIsNumeric) {
                bFindingChar = false;
                substr += s[j];
            } else if (!bFindingChar) {
                bFindingChar = true;
                CalcStr(substr);

            }
        }
        if (substr.size()) {
            CalcStr(substr);
        }
    }
    sort(results.begin(), results.end(), cmp);
    for (const string& result : results) {
        cout << result << "\n";
    }
    return 0;
}