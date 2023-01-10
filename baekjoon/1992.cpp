/**
 * 문제 제목 : 쿼드트리
 * 문제 링크 : https://www.acmicpc.net/problem/1992
 * 
 * 흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다.
 * 흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서 같은 숫자의 점들이 한 곳에 많이 몰려있으면, 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.
 * 주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다.
 * 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다
 * 위 그림에서 왼쪽의 영상은 오른쪽의 배열과 같이 숫자로 주어지며, 이 영상을 쿼드 트리 구조를 이용하여 압축하면 "(0(0011)(0(0111)01)1)"로 표현된다.
 * N × N 크기의 영상이 주어질 때, 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
string ret;

bool terrain[65][65];

void quad(int sy, int sx, int ey, int ex) {
    bool startChar = terrain[sy][sx];
    bool bIsSplited = false;
    if (ey - sy <= 1 || ex - sx <= 1) {
        ret += (char)terrain[sy][sx] + '0';
    }
    else {
        for (int y = sy; y < ey; y++) {
            if (bIsSplited) break;
            for (int x = sx; x < ex; x++) {
                if (terrain[y][x] != startChar) {
                    bIsSplited = true;
                    ret += "(";
                    int splity = (sy + ey) / 2;
                    int splitx = (sx + ex) / 2;
                    // 왼쪽 위
                    quad(sy, sx, splity, splitx);
                    // 오른쪽 위
                    quad(sy, splitx, splity, ex);
                    // 왼쪽 아래
                    quad(splity, sx, ey, splitx);
                    // 오른쪽 아래
                    quad(splity, splitx, ey, ex);       
                    break;
                }
            }
        }
        if (bIsSplited) ret += ")";
        else            ret += (char)startChar + '0';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < N; j++) {
            terrain[i][j] = (bool)(s[j] - '0');
        }
    }
    quad(0, 0, N, N);
    cout << ret;
    return 0;
}