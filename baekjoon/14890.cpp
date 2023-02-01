/**
 * 문제 제목 : 경사로
 * 문제 링크 : https://www.acmicpc.net/problem/14890
 *
 * 문제가 길어서 링크로 확인해야 함
 */

/**
 * 개선 전 문제 풀이 
 */
// #include <bits/stdc++.h>
// using namespace std;
// int n, l;
// int heights[101][101];
// bool bNeedRoad;
// bool colcheck(int y, int x, int prevHeight, int heightCnt) {
//     if (x >= n) {
//         return true;
//     }
//     if (bNeedRoad && heightCnt >= l) {
//         bNeedRoad = false;
//         heightCnt -= l;
//     }
//     int curHeight = heights[y][x];
//     if (curHeight == prevHeight) {
//         return colcheck(y, x + 1, curHeight, ++heightCnt);
//     }
//     else {
//         if (abs(curHeight - prevHeight) > 1 || bNeedRoad) return false;
//         if (curHeight > prevHeight) {
//             int roadStart = x - l;
//             if (roadStart < 0 || heightCnt < l) return false;
//         }
//         else {
//             int roadEnd = x + l - 1;
//             if (roadEnd >= n) return false;
//             bNeedRoad = true;
//         }
//         return colcheck(y, x + 1, curHeight, 1);
//     }
// }
// bool rowcheck(int y, int x, int prevHeight, int heightCnt) {
//     if (y >= n) {
//         return true;
//     }
//     if (bNeedRoad && heightCnt >= l) {
//         bNeedRoad = false;
//         heightCnt -= l;
//     }
//     int curHeight = heights[y][x];
//     if (curHeight == prevHeight) {
//         return rowcheck(y + 1, x, curHeight, ++heightCnt);
//     }
//     else {
//         if (abs(curHeight - prevHeight) > 1 || bNeedRoad) return false;
//         if (curHeight > prevHeight) {
//             int roadStart = y - l;
//             if (roadStart < 0 || heightCnt < l) return false;
//         }
//         else {
//             int roadEnd = y + l - 1;
//             if (roadEnd >= n) return false;
//             bNeedRoad = true;
//         }
//         return rowcheck(y + 1, x, curHeight, 1);
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cin >> n >> l;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) cin >> heights[i][j];
//     }
//     int ret = 0;
//     for (int i = 0; i < n; i++) {
//         bNeedRoad = false;
//         if (colcheck(i, 0, heights[i][0], 0)) ++ret;
//         bNeedRoad = false;
//         if (rowcheck(0, i, heights[0][i], 0)) ++ret;
//     }
//     cout << ret << '\n';
//     return 0;
// }

/**
 * 개선 후 문제 풀이 
 */
#include<bits/stdc++.h>
using namespace std; 
int n, l, a[104][104], b[104][104], ret; 
void solve(int a[104][104]){
    for(int i = 0; i < n; i++){
        int cnt = 1; 
        int j;  
        for(j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1])cnt++; 
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; 
            else if(a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; 
            else break;
        }
        if(j == n - 1 && cnt >= 0) ret++; 
    }
    return; 
} 
int main(){
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]); 
            b[j][i] = a[i][j];
        }
    }    
    solve(a); solve(b);  
    printf("%d\n", ret);  
    return 0; 
}