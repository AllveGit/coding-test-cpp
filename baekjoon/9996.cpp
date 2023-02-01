/**
 * 문제 제목 : 한국이 그리울 땐 서버에 접속하지
 * 문제 링크 : https://www.acmicpc.net/problem/9996
 *
 * 선영이는 이번 학기에 오스트레일리아로 교환 학생을 가게 되었다. 
 * 호주에 도착하고 처음 며칠은 한국 생각을 잊으면서 즐겁게 지냈다. 몇 주가 지나니 한국이 그리워지기 시작했다. 
 * 선영이는 한국에 두고온 서버에 접속해서 디렉토리 안에 들어있는 파일 이름을 보면서 그리움을 잊기로 했다. 
 * 매일 밤, 파일 이름을 보면서 파일 하나하나에 얽힌 사연을 기억하면서 한국을 생각하고 있었다.
 * 어느 날이었다. 한국에 있는 서버가 망가졌고, 그 결과 특정 패턴과 일치하는 파일 이름을 적절히 출력하지 못하는 버그가 생겼다.
 * 패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다.
 * 파일 이름이 패턴에 일치하려면, 패턴에 있는 별표를 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다. 별표는 빈 문자열로 바꿀 수도 있다. 
 * 예를 들어, "abcd", "ad", "anestonestod"는 모두 패턴 "a*d"와 일치한다. 하지만, "bcd"는 일치하지 않는다.
 * 패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이 패턴과 일치하는지 아닌지를 구하는 프로그램을 작성하시오.
 */

/**
 * 개선 전 문제 풀이 
 */
// #include <bits/stdc++.h>
// using namespace std;

// int Cnt;
// string Pattern;
// string Inputs[101];

// vector<string> Split(string InString, const string& InDelimeter)
// {
//     vector<string> ret;
//     long long pos;
//     string token = "";
//     while ((pos = InString.find(InDelimeter)) != string::npos)
//     {
//         token = InString.substr(0, pos);
//         ret.push_back(token);
//         InString.erase(0, pos + InDelimeter.length());
//     }
//     ret.push_back(InString);
//     return ret;
// }

// int main()
// {
//     cin >> Cnt;

//     cin >> Pattern;

//     vector<string> splitPattern = Split(Pattern, "*");
//     string beginPattern = splitPattern[0];
//     string endPattern = splitPattern[1];

//     for (int i = 0; i < Cnt; i++)
//     {
//         cin >> Inputs[i];
//     }

//     long long pos;
//     for (int i = 0; i < Cnt; i++)
//     {
//         string s = Inputs[i];
//         pos = s.find(beginPattern);
//         if (pos == string::npos || pos != 0)
//         {
//             cout << "NE" << "\n";
//             continue;
//         }

//         s.erase(0, beginPattern.length());

//         pos = s.rfind(endPattern);
//         if (pos == string::npos || pos != (s.length() - endPattern.length()))
//         {
//             cout << "NE" << "\n";
//             continue;
//         }

//         cout << "DA" << "\n";
//     }

//     return 0;
// }

/**
 * 개선 후 문제 풀이 
 */
#include<bits/stdc++.h> 
using namespace std;   
int n; 
string s, ori_s, pre, suf; 
int main(){
    cin >> n;
    cin >> ori_s;  
    int pos = ori_s.find('*');  
    pre = ori_s.substr(0, pos); 
    suf = ori_s.substr(pos + 1); 
    for(int i = 0; i < n; i++){
        cin >> s; 
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";
        }else{
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout <<"NE\n";  
        } 
    } 
    return 0;
} 