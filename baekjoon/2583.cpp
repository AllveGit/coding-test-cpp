/**
 * 문제 제목 : 영역 구하기
 * 문제 링크 : https://www.acmicpc.net/problem/2583
 * 
 * 눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다.
 * 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
 * 예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
 * <그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
 * M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.
 */
#include <bits/stdc++.h>
using namespace std;

// 1 <= M, N, K <= 100
int M, N, K;
int sy, sx, ey, ex;
bool terrain[101][101];
bool visited[101][101];
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

void dfs(int y, int x, int& ret) {
    visited[y][x] = true;
    ++ret;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N || terrain[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx, ret);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> sx >> sy >> ex >> ey;
        for (int fy = sy; fy < ey; fy++) {
            for (int fx = sx; fx < ex; fx++) {
                terrain[fy][fx] = true;
            }
        }
    }

    vector<int> result;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (!terrain[y][x] && !visited[y][x]) {
                int ret = 0;
                dfs(y, x, ret);
                result.push_back(ret);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto elem : result) {
        cout << elem << " ";
    }
    return 0;
}