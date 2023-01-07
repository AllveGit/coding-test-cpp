/**
 * 문제 제목 : 패션왕 신해빈
 * 문제 링크 : https://www.acmicpc.net/problem/9375
 * 
 * 해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다.
 * 예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다.
 * 해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?
 */

#include <bits/stdc++.h>
using namespace std;

int case_num;
int clothes_num;
string clothes_name, clothes_type;
map<string, int> closet;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> case_num;
    for (int i = 0; i < case_num; i++) {
        cin >> clothes_num;
        for (int j = 0; j < clothes_num; j++) {
            cin >> clothes_name >> clothes_type;
            if (closet.find(clothes_type) == closet.end())  closet[clothes_type] = 1;
            else                                            closet[clothes_type]++;
        }

        long long ret = 1;
        for (const auto& iter : closet)
        {
            ret *= ((long long)iter.second + 1);
        }
        ret -= 1;

        cout << ret << "\n";

        closet.clear();
    }

    return 0;
}