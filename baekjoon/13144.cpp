/**
 * 문제 제목 : List of Unique Numbers
 * 문제 링크 : https://www.acmicpc.net/problem/13144
 *
 * 길이가 N인 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하여라.
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
long long s, e, cnt[100001], n, a[100001];
long long ret;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", a + i);
    }
    while(e < n){
        if(!cnt[a[e]]){
            cnt[a[e]]++;
            e++;
        }else{
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    printf("%lld\n", ret);
    return 0;
}