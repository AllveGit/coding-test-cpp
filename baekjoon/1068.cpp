/**
 * 문제 제목 : 트리
 * 문제 링크 : https://www.acmicpc.net/problem/1068
 *
 * 문제가 길어서 링크로 확인해야 함
 */

#include <bits/stdc++.h>
using namespace std;
int N, Parent, Del;
vector<int> rootNodes;
vector<int> nodeChilds[50];
int solve(int startIndex, int delNode) {
    if (startIndex == delNode) return 0;
    if (nodeChilds[startIndex].size() == 0) return 1;
    int ret = 0;
    bool bFlag = false;
    for (int child : nodeChilds[startIndex]) {
        int solveRet = solve(child, delNode);
        if (solveRet == 0) bFlag = true;
        ret += solveRet;
    }
    if (bFlag && nodeChilds[startIndex].size() == 1) ret += 1;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Parent;
        if (Parent == -1) {
            rootNodes.push_back(i);
        }
        else {
            nodeChilds[Parent].push_back(i);
        }
    }
    cin >> Del;
    int ret = 0;
    for (int rootNode : rootNodes) {
        ret += solve(rootNode, Del);
    }
    cout << ret;
    return 0;
}