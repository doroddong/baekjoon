//
//  main.cpp
//  1932_정수삼각형
//
//  Created by 이동훈 on 2020/10/06.
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,ans=0;
int tri[501][501];
int dp[501][501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int temp;
            cin >> temp;
            tri[i][j] = temp;
        }
    }
    
    dp[1][1] = tri[1][1];
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
                dp[i][j] = dp[i-1][j] + tri[i][j];
            }
            else if(j==i){
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j] + tri[i][j], dp[i-1][j-1]+ tri[i][j]);
            }
            
            if(i==n){
                ans = max(ans,dp[i][j]);
            }
        }
    }
    
    cout << ans <<endl;
    
    
    
  
    return 0;
}

