/**
 * 문제 제목 : 일곱 난쟁이
 * 문제 링크 : https://www.acmicpc.net/problem/10808
 *
 * 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int nums[26];

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        int arrIndex = (int)s[i] - (int)'a';
        ++nums[arrIndex];
    }

    for (int i = 0; i < 26; i++)
    {
        cout << nums[i];
        
        if (i <= 24)
        {
            cout << " ";
        }
    }

    return 0;
}