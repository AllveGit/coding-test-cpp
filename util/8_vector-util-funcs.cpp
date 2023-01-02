#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // accumulate : 벡터의 값들의 총합을 구해주는 함수
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << "\n";

    // max_element : 벡터의 값들 중 가장 큰 요소를 추출하는 함수 (iterator로 반환하므로 *를 해줘야 값으로 변환됨)
    int max = *max_element(v.begin(), v.end());
    cout << max << "\n";
}