/**
 * 문제 제목 : 멀티탭 스케줄링
 * 문제 링크 : https://www.acmicpc.net/problem/1700
 * 
 * 기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다. 
 * 준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다.
 * 그래서 준규는 자신의 생활 패턴을 분석하여, 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.
 * 예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면,
 *      1. 키보드
 *      2. 헤어드라이기
 *      3. 핸드폰 충전기
 *      4. 디지털 카메라 충전기
 *      5. 키보드
 *      6. 헤어드라이기
 * 키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰 충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다.
 */

#include <bits/stdc++.h>
using namespace std;
int n, k, c, ret;
vector<int> o;
queue<int> idxs[101];
set<int> t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> c;
        o.push_back(c);
        idxs[c].push(i+1);
        cnt[c]++;
    }
    for (int i = 0; i < k; i++) {
        bool bContain = t.find(o[i]) != t.end();
        if (t.size() == n && !bContain) {
            int maxCnt = 0, maxIdx = -1;
            for (auto iter : t) {
                if (idxs[iter].size() == 0) {
                    maxIdx = iter;
                    break;
                }
                if (maxCnt < idxs[iter].front()) {
                    maxCnt = idxs[iter].front();
                    maxIdx = iter;
                }
            }

            t.erase(maxIdx);
            ++ret;

            t.insert(o[i]);
            if (idxs[o[i]].size()) idxs[o[i]].pop();
        }
        else if (bContain) {
            if (idxs[o[i]].size()) idxs[o[i]].pop();
        }
        else if (t.size() < n) {
            t.insert(o[i]);
            if (idxs[o[i]].size()) idxs[o[i]].pop();
        }
    }
    cout << ret;
    return 0;
}