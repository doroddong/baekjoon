//
//  main.cpp
//  7579_앱
//
//  Created by 이동훈 on 2020/09/29.
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
#define MAX 101
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int cost[MAX], memory[MAX]; //cost : 앱의 비용 , memory : 앱의 메모리 크기
int dp[101][10001]; // dp[n][m] : n개의 앱을 사용했을 때, m의 비용을 사용하면서 얻을 수 있는 최대 메모리

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> memory[i];
    }
    
    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    
    int ans = INF;
    
    dp[0][cost[0]] = memory[0];
    for(int i=1;i<n;i++){                      // i개의 앱을 선택
        for(int j=0;j<=10000;j++){            // 0<= n,c <=100 이므로 최대 비용은 100*100 = 10000임
            
            // i번쨰 앱을 선택했을 때, cost가 들어갈 수 있어야함
            if(j>=cost[i]){
                // 들어갈 수 있는 cost에서의 최대 메모리에 현재 메모리 추가
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+memory[i]);
            }
            // i번쨰 선택 X, 이전의 것 그대로 가져옴
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
            // 최대 메모리가 m 이상이라면, 최소 비용을 저장
            if(dp[i][j]>=m) {
                ans = min(ans,j);
            }
        }
    }
    
    cout<< ans <<endl;
  
    return 0;
}
