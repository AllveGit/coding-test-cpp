/**
 * 문제 제목 : 수열
 * 문제 링크 : https://www.acmicpc.net/problem/2559
 *
 * 매일 아침 9시에 학교에서 측정한 온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 알아보고자 한다.
 * 예를 들어, 아래와 같이 10일 간의 온도가 주어졌을 때,
 * 3 -2 -4 -9 0 3 7 13 8 -3
 * 모든 연속적인 이틀간의 온도의 합은 아래와 같다.
 * 이때, 온도의 합이 가장 큰 값은 21이다. 
 * 
 * 모든 연속적인 5일 간의 온도의 합은 아래와 같으며, 
 * 이때, 온도의 합이 가장 큰 값은 31이다.
 * 매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램을 작성하시오. 
 */

/**
 * 개선 전 문제 풀이 
 */
// #include <bits/stdc++.h>
// using namespace std;

// queue<int> arr;
// int arrNums, selectNum;
// int sum = 0;
// int maxSum = INT_MIN;

// int main()
// {
//     cin >> arrNums >> selectNum;

//     for (int i = 0; i < arrNums; i++)
//     {
//         int value;
//         cin >> value;

//         sum += value;

//         arr.push(value);

//         if (arr.size() == selectNum) 
//         {
//             if (maxSum < sum)
//             {
//                 maxSum = sum;
//             }

//             int subVal = arr.front();
//             sum -= subVal;
//             arr.pop();
//         }
//     }

//     cout << maxSum;

//     return 0;
// }

/**
 * 개선 후 문제 풀이 
 */
#include<bits/stdc++.h> 
using namespace std;  
typedef long long ll;  
int n, k, temp, psum[100001], ret = -1000000; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k; 
	for(int i = 1; i <= n; i++){
		cin >> temp; psum[i] = psum[i - 1] + temp; 
	} 
	for(int i = k; i <= n; i++){
		ret = max(ret, psum[i] - psum[i - k]);
	}
	cout << ret << "\n";
    return 0;
}