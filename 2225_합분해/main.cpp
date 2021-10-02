//
//  main.cpp
//  2225_합분해
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,k;
int dp[201][201];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>> n >> k;
    
    for(int i=0;i<=n;i++){
        dp[1][i] = 1;
    }
    
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(j+k<=n)  {
                    dp[i][j+k] += dp[i-1][j];
                    dp[i][j+k] %=1000000000;
                }
            }
        }
    }
    
    cout<< dp[k][n] % 1000000000<<endl;
    
  
    return 0;
}
