/**
 * 문제 제목 : 집합
 * 문제 링크 : https://www.acmicpc.net/problem/14391
 * 
 * 영선이는 숫자가 쓰여 있는 직사각형 종이를 가지고 있다. 
 * 종이는 1×1 크기의 정사각형 칸으로 나누어져 있고, 숫자는 각 칸에 하나씩 쓰여 있다. 
 * 행은 위에서부터 아래까지 번호가 매겨져 있고, 열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.
 * 영선이는 직사각형을 겹치지 않는 조각으로 자르려고 한다.
 * 각 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다.
 * 길이가 N인 조각은 N자리 수로 나타낼 수 있다.
 * 가로 조각은 왼쪽부터 오른쪽까지 수를 이어 붙인 것이고, 세로 조각은 위에서부터 아래까지 수를 이어붙인 것이다.
 * 아래 그림은 4×4 크기의 종이를 자른 한 가지 방법이다.
 */

#include <bits/stdc++.h>
using namespace std;
int a[4][4], n, m, ret; 
int main() { 
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d",&a[i][j]);
        }
    } 
    for (int s = 0; s < (1 << (n * m)); s++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                int k = i * m + j;
                if ((s & (1<<k)) == 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int k = i * m + j;
                if ((s & (1<<k)) != 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret,sum);
    }
    cout << ret << '\n';
    return 0;
}