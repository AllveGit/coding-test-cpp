/**
 * 문제 제목 : 유기농 배추
 * 문제 링크 : https://www.acmicpc.net/problem/2828
 * 
 * 상근이는 오락실에서 바구니를 옮기는 오래된 게임을 한다.
 * 스크린은 N칸으로 나누어져 있다.
 * 스크린의 아래쪽에는 M칸을 차지하는 바구니가 있다.
 * (M<N) 플레이어는 게임을 하는 중에 바구니를 왼쪽이나 오른쪽으로 이동할 수 있다.
 * 하지만, 바구니는 스크린의 경계를 넘어가면 안 된다. 가장 처음에 바구니는 왼쪽 M칸을 차지하고 있다.
 * 한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다.
 * 스크린의 위에서 사과 여러 개가 떨어진다. 
 * 각 사과는 N칸중 한 칸의 상단에서 떨어지기 시작하며, 스크린의 바닥에 닿을때까지 직선으로 떨어진다. 한 사과가 바닥에 닿는 즉시, 다른 사과가 떨어지기 시작한다.
 * 바구니가 사과가 떨어지는 칸을 차지하고 있다면, 바구니는 그 사과가 바닥에 닿을 때, 사과를 담을 수 있다.
 * 상근이는 사과를 모두 담으려고 한다. 이때, 바구니의 이동 거리의 최솟값을 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;
int J;
vector<int> appleIndexs;

int MoveBasket(int inCurIndex, int inAppleIndex) {
    if (inCurIndex <= inAppleIndex && inCurIndex + (M - 1) >= inAppleIndex) {
        return 0;
    }

    if (inAppleIndex > inCurIndex)  return inAppleIndex - (inCurIndex + (M - 1));
    else                            return inAppleIndex - inCurIndex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> J;
    for (int i = 0; i < J; i++) {
        int appleIndex;
        cin >> appleIndex;
        appleIndexs.push_back(appleIndex);
    }

    int curIndex = 1;
    int totalMove = 0;
    for (int appleIndex : appleIndexs) {
        int moveNum = MoveBasket(curIndex, appleIndex);
        curIndex += moveNum;
        totalMove += abs(moveNum);
    }

    cout << totalMove;
    return 0;
}