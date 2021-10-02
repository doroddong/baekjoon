//
//  main.cpp
//  11057_오르막수
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
#define MAX 1001
#define INF 987654321
#define endl "\n"

using namespace std;

// dp[n][k] : n자리수이고 끝의 자리수가 k인 오르막 수의 개수
int dp[MAX][10];
int n;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    // 초기값 세팅
    for(int i=0;i<10;i++){
        dp[1][i] = 1;
    }
    
    // 이전 자리수인 오르막수 중에서 끝의 수보다 크거나 같은 수를 붙여서 저장
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k = j; k<10;k++){
                dp[i][k] += dp[i-1][j];
                dp[i][j] %= 10007;
            }
        }
    }
    
    int sum = 0;
    
    for(int i=0;i<10;i++){
        sum += dp[n][i];
    }
    
    cout<< sum % 10007<<endl;
    
  
    return 0;
}
