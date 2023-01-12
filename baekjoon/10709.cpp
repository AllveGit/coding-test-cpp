/**
 * 문제 제목 : 기상캐스터
 * 문제 링크 : https://www.acmicpc.net/problem/10709
 * 
 * JOI시는 남북방향이 H 킬로미터, 동서방향이 W 킬로미터인 직사각형 모양이다.
 * JOI시는 가로와 세로의 길이가 1킬로미터인 H × W 개의 작은 구역들로 나뉘어 있다.
 * 각 구역의 하늘에는 구름이 있을 수도, 없을 수도 있다.
 * 모든 구름은 1분이 지날 때마다 1킬로미터씩 동쪽으로 이동한다.
 * 오늘은 날씨가 정말 좋기 때문에 JOI시의 외부에서 구름이 이동해 오는 경우는 없다.
 * 지금 각 구역의 하늘에 구름이 있는지 없는지를 알고 있다.
 * 기상청에서 일하고 있는 여러분은 각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지를 예측하는 일을 맡았다.
 * 각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지를 구하여라.
 */

#include <bits/stdc++.h>
using namespace std;

int H, W;
string s;
int sky[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        int cloudIdx = -1;
        cin >> s;
        for (int j = 0; j < W; j++) {
            char c = s[j];
            if (c == 'c') {
                cloudIdx = j;
                sky[i][j] = 0;
            } else {
                if (cloudIdx == -1) sky[i][j] = -1;
                else                sky[i][j] = j - cloudIdx;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << sky[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}