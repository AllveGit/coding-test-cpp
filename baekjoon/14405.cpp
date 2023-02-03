/**
 * 문제 제목 : 피카츄
 * 문제 링크 : https://www.acmicpc.net/problem/14405
 *
 * 피카츄는 "pi", "ka", "chu"를 발음할 수 있다. 
 * 따라서, 피카츄는 이 세 음절을 합친 단어만 발음할 수 있다. 
 * 예를 들면, "pikapi"와 "pikachu"가 있다.
 * 문자열 S가 주어졌을 때, 피카츄가 발음할 수 있는 문자열인지 아닌지 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;
string s;
string arr[3] = { "pi", "ka", "chu" };
bool bRet = true;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < 3; i++) {
        const string replaceStr = "*";
        size_t pos;
        while ((pos = s.find(arr[i])) != std::string::npos) {
            s.replace(pos, arr[i].size(), replaceStr);
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '*') { bRet = false; break; }
    }
    cout << (bRet ? "YES" : "NO");
    return 0;
}