/**
 * 문제 제목 : 비밀번호 발음하기
 * 문제 링크 : https://www.acmicpc.net/problem/4659
 * 
 * 좋은 패스워드를 만드는것은 어려운 일이다.
 * 대부분의 사용자들은 buddy처럼 발음하기 좋고 기억하기 쉬운 패스워드를 원하나, 이런 패스워드들은 보안의 문제가 발생한다.
 * 어떤 사이트들은 xvtpzyo 같은 비밀번호를 무작위로 부여해 주기도 하지만, 사용자들은 이를 외우는데 어려움을 느끼고 심지어는 포스트잇에 적어 컴퓨터에 붙여놓는다.
 * 가장 이상적인 해결법은 '발음이 가능한' 패스워드를 만드는 것으로 적당히 외우기 쉬우면서도 안전하게 계정을 지킬 수 있다.
 * 회사 FnordCom은 그런 패스워드 생성기를 만들려고 계획중이다.
 * 당신은 그 회사 품질 관리 부서의 직원으로 생성기를 테스트해보고 생성되는 패스워드의 품질을 평가하여야 한다.
 * 높은 품질을 가진 비밀번호의 조건은 다음과 같다.
 * 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
 * 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
 * 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
 * 이 규칙은 완벽하지 않다;우리에게 친숙하거나 발음이 쉬운 단어 중에서도 품질이 낮게 평가되는 경우가 많이 있다.
 */

#include <bits/stdc++.h>
using namespace std;

string s;

bool IsVowels(char check) {
    return check == 'a' || check == 'e' || check == 'i' || check == 'o' || check == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> s;
        if (s == "end") break;
        bool bIsVowels = false;
        bool bContainVowels = false;
        bool bEvalFailed = false;
        int repeatCnt = 0;
        char lastChar;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            bool bIsNewVowels = IsVowels(c);
            if (bIsNewVowels) bContainVowels = true;
            if (bIsVowels != bIsNewVowels) repeatCnt = 1;
            else ++repeatCnt;

            if (repeatCnt >= 3 || (i >= 1 && lastChar != 'o' && lastChar != 'e' && lastChar == c)) {
                bEvalFailed = true;
                break;
            }
            bIsVowels = bIsNewVowels;
            lastChar = c;
        }

        if (bEvalFailed || !bContainVowels) cout << "<" << s << ">" << " " << "is not acceptable.";
        else                                cout << "<" << s << ">" << " " << "is acceptable.";
        cout << "\n";
    }

    return 0;
}