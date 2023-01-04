/**
 * 문제 제목 : 팰린드롬
 * 문제 링크 : https://www.acmicpc.net/problem/10988
 *
 * 알파벳 소문자로만 이루어진 단어가 주어진다. 이때, 이 단어가 팰린드롬인지 아닌지 확인하는 프로그램을 작성하시오.
 * 팰린드롬이란 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말한다. 
 * level, noon은 팰린드롬이고, baekjoon, online, judge는 팰린드롬이 아니다.
 */

#include <bits/stdc++.h>
using namespace std;

string str;

int solve(string& InString)
{
    int prefix = 0;
    int suffix = InString.length() - 1;

    while (prefix < suffix)
    {
        if (InString[prefix] != InString[suffix])
        {
            return 0;
        }

        prefix += 1;
        suffix -= 1;
    }

    return 1;
}

int main()
{
    cin >> str;

    cout << solve(str);

    return 0;
}