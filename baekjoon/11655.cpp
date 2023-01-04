/**
 * 문제 제목 : ROT13
 * 문제 링크 : https://www.acmicpc.net/problem/11655
 * 
 * ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.
 * 예를 들어, "Baekjoon Online Judge"를 ROT13으로 암호화하면 "Onrxwbba Bayvar Whqtr"가 된다. ROT13으로 암호화한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13하면 된다. 
 * 앞에서 암호화한 문자열 "Onrxwbba Bayvar Whqtr"에 다시 ROT13을 적용하면 "Baekjoon Online Judge"가 된다.
 * ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다. 예를 들어, "One is 1"을 ROT13으로 암호화하면 "Bar vf 1"이 된다.
 * 문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

const int ASCII_A = (int)'A';
const int ASCII_Z = (int)'Z';
const int ASCII_a = (int)'a';
const int ASCII_z = (int)'z';

string s;

void ROT13(string& InString)
{
    for (int i = 0; i < InString.length(); i++)
    {
        int c = (int)InString[i];

        if (!((c >= ASCII_A && c <= ASCII_Z) || (c >= ASCII_a && c <= ASCII_z)))
            continue;

        const bool bIsSmallLetter = c >= ASCII_a;
        c += 13;

        if (bIsSmallLetter && c > ASCII_z)
        {
            c = (ASCII_a - 1) + (c - ASCII_z);
        }
        else if (!bIsSmallLetter && c > ASCII_Z)
        {
            c = (ASCII_A - 1) + (c - ASCII_Z);
        }

        InString[i] = (char)c;
    }
}

int main()
{
    getline(cin, s);

    ROT13(s);
    cout << s;

    return 0;
}