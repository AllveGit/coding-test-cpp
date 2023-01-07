/**
 * 문제 제목 : 나는야 포켓몬 마스터 이다솜
 * 문제 링크 : https://www.acmicpc.net/problem/1620 
 * 
 * 문제가 길어서 링크로 확인해야 함.
 */

#include <bits/stdc++.h>
using namespace std;

string arrs[100004];
unordered_map<string, int> maps;
int N, M;
string pokemonName;
int pokemonID;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> pokemonName;
        maps[pokemonName] = i;
        arrs[i] = pokemonName;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> pokemonName;
        pokemonID = atoi(pokemonName.c_str());
        if (pokemonID == 0) cout << maps[pokemonName] << "\n";
        else                cout << arrs[pokemonID] << "\n";
    }

    return 0;
}