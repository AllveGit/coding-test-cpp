/**
 * 문제 제목 : 주몽
 * 문제 링크 : https://www.acmicpc.net/problem/1940
 * 
 * 주몽은 철기군을 양성하기 위한 프로젝트에 나섰다.
 * 그래서 야철대장을 통해 철기군이 입을 갑옷을 만들게 하였다.
 * 야철대장은 주몽의 명에 따르기 위하여 연구에 착수하던 중 아래와 같은 사실을 발견하게 되었다.
 * 갑옷을 만드는 재료들은 각각 고유한 번호를 가지고 있다.
 * 갑옷은 두 개의 재료로 만드는데 두 재료의 고유한 번호를 합쳐서 M(1 ≤ M ≤ 10,000,000)이 되면 갑옷이 만들어 지게 된다.
 * 야철대장은 자신이 만들고 있는 재료를 가지고 갑옷을 몇 개나 만들 수 있는지 궁금해졌다.
 * 이러한 궁금증을 풀어 주기 위하여 N(1 ≤ N ≤ 15,000) 개의 재료와 M이 주어졌을 때 몇 개의 갑옷을 만들 수 있는지를 구하는 프로그램을 작성하시오.
 */

#include <bits/stdc++.h>
using namespace std;

int N, M;
int MaterialID;
set<int> MaterialIDs;
int TotalCombiCnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    if (M > 200000) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> MaterialID;
        if (MaterialID >= M) {
            continue;
        }
        
        int diffID = M - MaterialID;
        if (MaterialID == diffID) {
            continue;
        }

        if (MaterialIDs.find(diffID) != MaterialIDs.end()) {
            ++TotalCombiCnt;
        }
        else {
            MaterialIDs.insert(MaterialID);
        }
    }

    cout << TotalCombiCnt;
    return 0;
}