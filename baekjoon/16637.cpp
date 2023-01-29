/**
 * 문제 제목 : 괄호 추가하기
 * 문제 링크 : https://www.acmicpc.net/problem/16637
 * 
 * 길이가 N인 수식이 있다.
 * 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다.
 * 연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다.
 * 예를 들어, 3+8×7-9×2의 결과는 136이다.
 * 수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다.
 * 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다.
 * 예를 들어, 3+8×7-9×2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다.
 * 하지만, 중첩된 괄호는 사용할 수 없다.
 * 즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.
 * 수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오.
 * 추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.
 */

#include <bits/stdc++.h>
using namespace std;
int N;
int MaxValue = -900000000;
string s;
vector<int> nums;
vector<char> opers;
int oper(char a, int b, int c) {
    if (a == '+')       return b + c;
    else if (a == '-')  return b - c;
    else                return b * c;
}
void solve(int step, int value)
{
	if (step == nums.size() - 1)
	{
        MaxValue = max(MaxValue, value);
        return;
	}
    solve(step + 1, oper(opers[step], value, nums[step + 1]));
	if(step + 2 <= nums.size() - 1)
	{
        int temp = oper(opers[step + 1], nums[step + 1], nums[step + 2]);
        solve(step + 2, oper(opers[step], value, temp));
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) nums.push_back(atoi(&s[i]));
        else            opers.push_back(s[i]);
    }
    solve(0, nums[0]);
    cout << MaxValue;
}