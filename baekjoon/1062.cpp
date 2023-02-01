/**
 * 문제 제목 : 가르침
 * 문제 링크 : https://www.acmicpc.net/problem/1062
 *
 * 남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다.
 * 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다.
 * 김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다.
 * 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.
 * 남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.
 */
#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int ret = 0;
int words[55];
const int ESSENTIAL = 5;
int essentialWords;
void go(int start, int depth, int learnWords) {
    if (depth >= k - ESSENTIAL) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (words[i] == (words[i] & learnWords)) ++cnt;
        }
        if (ret < cnt) ret = cnt;
        return;
    }
    for (int i = start; i < 26; i++) {
        int bitMask = (1 << i);
        if (learnWords & bitMask) continue;
        go(i + 1, depth + 1, learnWords | bitMask);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            words[i] |=  (1 << (s[j]-'a'));
        }
    }
    if (k < ESSENTIAL) { cout << ret; return 0; }
    essentialWords |= (1 << ('a'-'a'));
    essentialWords |= (1 << ('n'-'a'));
    essentialWords |= (1 << ('t'-'a'));
    essentialWords |= (1 << ('i'-'a'));
    essentialWords |= (1 << ('c'-'a'));
    go(0, 0, essentialWords);
    cout << ret;
    return 0;
}