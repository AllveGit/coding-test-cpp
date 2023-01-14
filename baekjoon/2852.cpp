/**
 * 문제 제목 : NBA 농구
 * 문제 링크 : https://www.acmicpc.net/problem/2852
 *
 * 동혁이는 NBA 농구 경기를 즐겨 본다. 동혁이는 골이 들어갈 때 마다 골이 들어간 시간과 팀을 적는 이상한 취미를 가지고 있다.
 * 농구 경기는 정확히 48분동안 진행된다. 각 팀이 몇 분동안 이기고 있었는지 출력하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int N;
const int PlaySecs = 48 * 60;
int score1, score2;
int winSec1, winSec2;
int whowin = -1;

int main() {
    scanf("%d", &N);
    int t, m, s;
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        scanf("%d:%d", &m, &s);
        const int curSec = m * 60 + s;
        const int diffSec = PlaySecs - curSec;
        if (t == 1) ++score1;
        else        ++score2;
        if (score1 > score2) {
            if (whowin != 1) {
                winSec1 += diffSec;
                if (whowin == 2) winSec2 = winSec2 - diffSec >= 0 ? winSec2 - diffSec : 0;
            }
            whowin = 1;
        }
        else if (score1 < score2) {
            if (whowin != 2) {
                winSec2 += PlaySecs - curSec;
                if (whowin == 1) winSec1 = winSec1 - diffSec >= 0 ? winSec1 - diffSec : 0;
            }
            whowin = 2;
        }
        else {
            if (whowin == 1) winSec1 = winSec1 - diffSec >= 0 ? winSec1 - diffSec : 0;
            if (whowin == 2) winSec2 = winSec2 - diffSec >= 0 ? winSec2 - diffSec : 0;
            whowin = -1;
        }
    }
    const int retMinute1 = winSec1 / 60;
    const int retSec1 = winSec1 % 60;
    printf("%02d:%02d\n", retMinute1, retSec1);
    const int retMinute2 = winSec2 / 60;
    const int retSec2 = winSec2 % 60;
    printf("%02d:%02d\n", retMinute2, retSec2);
    return 0;
}