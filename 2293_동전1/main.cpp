//
//  main.cpp
//  2293_동전1
//
//  Created by 이동훈 on 2020/09/27.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 10001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,k;
int dp[MAX];
int coin[100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++)    cin >> coin[i];
    
    dp[0] = 1;
    
    for(int i=0;i<n;i++){
        // 새로운 동전으로 만들수 있는 경우의 수 계산
        int cur_coin = coin[i];
        for(int j=cur_coin; j<=k; j++){
            // 새로운 동전을 추가하여 경우의 수를 만듬
            // -> ( j - cur_coin) 가치를 만들 수 있는 경우의 수에 더함
            dp[j] += dp[j-cur_coin];
        }
    }
    cout << dp[k] <<endl;
    
    return 0;
}
