/**
 * 문제 제목 : 팰린드롬 만들기
 * 문제 링크 : https://www.acmicpc.net/problem/1213
 * 
 * 임한수와 임문빈은 서로 사랑하는 사이이다.
 * 임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.
 * 임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.
 * 임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

string s;
string pelindrome;
int cnts[26];
int odd, even;
int st, ed;
bool bHasCenter = false;
char centerChar;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        ++cnts[(int)(s[i] - 'A')];
    }

    for (int i = 0; i < 26; i++) {
        if (cnts[i] <= 0)       continue;
        if (cnts[i] % 2 == 0)   ++even;
        else                    ++odd;
    }

    if (odd > 1) {
        cout << "I'm Sorry Hansoo";
    }
    else {
        pelindrome.resize(s.length());
        st = 0;
        ed = s.length() - 1;
        for (int i = 0; i < 26; i++) {
            if (cnts[i] <= 0)
                continue;

            const char curChar = 'A' + i;
            int curCnt = cnts[i];
            if (curCnt % 2 == 1) {
                bHasCenter = true;
                centerChar = curChar;
                --curCnt;
            }

            while (curCnt > 0) {
                pelindrome[st] = curChar;
                pelindrome[ed] = curChar;
                ++st;
                --ed;
                curCnt -= 2;
            }
        }
        if (bHasCenter) {
            pelindrome[s.length() / 2] = centerChar;
        }
        cout << pelindrome << "\n";
    }

    return 0;
}