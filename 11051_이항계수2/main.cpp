//
//  main.cpp
//  11051_이항계수2
//
//  Created by 이동훈 on 2020/09/30.
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

typedef long long ll;
typedef pair<int,int> pii;

int n,k;
int dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i==j || j==0){
                dp[i][j] =1;
            }
            else    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%10007;
        }
    }
    
    cout<<dp[n][k]<<endl;
  
    return 0;
}
