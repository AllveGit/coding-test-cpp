#include <bits/stdc++.h>
using namespace std;

/** 
 * 누적합 
 * 
 * 배열의 각 구간까지의 요소들의 합을 캐싱하여 푸는 방법
 * 
 * 배열의 요소가 중간중간에 바뀌는 동적배열에는 쓸 수 없다
 * 배열의 요소들이 고정되어있는 정적배열에만 사용할 수 있다.
 * 
 * 앞에서부터 합을 더하는 것은 prefixsum
 * 뒤에서부터 합을 더하는 것은 suffixsum (코딩테스트에 안나옴, 알고리즘 대회 같은 곳에서만 나옴)
 */

int arr[100004];
int psum[100004];
int b, c, n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << "\n";
    }

    return 0;
}