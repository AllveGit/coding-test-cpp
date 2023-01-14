/**
 * 문제 제목 : 균형잡힌 세상
 * 문제 링크 : https://www.acmicpc.net/problem/4949
 *
 * 세계는 균형이 잘 잡혀있어야 한다.
 * 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.
 * 정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.
 * 문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.
 * 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
 * 모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
 * 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
 * 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
 * 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
 * 정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& str, const string& delimeter) {
    vector<string> ret;
    string token = "";
    long long pos = 0;
    while ((pos = str.find(delimeter)) != string::npos) {
        token = str.substr(0, pos);
        ret.push_back(token);
        str.erase(0, pos + delimeter.size());
    }
    if (str.size() > 0) ret.push_back(str);
    return ret;
}

bool check(const string& str) {
    stack<char> pairs;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '(' || c == '[') {
            pairs.push(c);
        }
        else if (c == ')') {
            if (pairs.empty() || pairs.top() != '(') return false;
            pairs.pop();
        }
        else if (c == ']') {
            if (pairs.empty()|| pairs.top() != '[') return false;
            pairs.pop();
        }
    }
    return pairs.empty();
}

string s;
vector<bool> rets;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        getline(cin, s);
        if (s == ".") break;
        vector<string> strs = split(s, ".");
        for (const string& str : strs) {
            rets.push_back(check(str));
        }
    }
    for (bool ret : rets) {
        if (ret)    cout << "yes";
        else        cout << "no";
        cout << "\n";
    }
    return 0;
}