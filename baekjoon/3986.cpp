/**
 * 문제 제목 : 좋은 단어
 * 문제 링크 : https://www.acmicpc.net/problem/3986
 * 
 * 이번 계절학기에 심리학 개론을 수강 중인 평석이는 오늘 자정까지 보고서를 제출해야 한다. 
 * 보고서 작성이 너무 지루했던 평석이는 노트북에 엎드려서 꾸벅꾸벅 졸다가 제출 마감 1시간 전에 깨고 말았다.
 * 안타깝게도 자는 동안 키보드가 잘못 눌려서 보고서의 모든 글자가 A와 B로 바뀌어 버렸다!
 * 그래서 평석이는 보고서 작성을 때려치우고 보고서에서 '좋은 단어'나 세보기로 마음 먹었다.
 * 평석이는 단어 위로 아치형 곡선을 그어 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다. 
 * 만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을수 있다면, 그 단어는 '좋은 단어'이다. 
 * 평석이가 '좋은 단어' 개수를 세는 것을 도와주자.
 */

#include <bits/stdc++.h>
using namespace std;

int N;
int TotalCnt;
vector<string> strs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str.length() % 2 != 0)
            continue;
        strs.push_back(str);    
    }

    for (const string& s : strs) {
        stack<char> chrStacks;
        for (char c : s) {
            if (chrStacks.size() && chrStacks.top() == c)   chrStacks.pop();
            else                                            chrStacks.push(c);
        }
        if (chrStacks.size() == 0)
            ++TotalCnt;
    }

    cout << TotalCnt;

    return 0;
}