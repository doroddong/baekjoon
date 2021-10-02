//
//  main.cpp
//  12865_평범한배낭
//
//  Created by 이동훈 on 2020/09/10.
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
int arr[101][2];
int dp[101][100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            // 아이템의 정보를 가짐
            int w = arr[i][0];
            int v = arr[i][1];
            
            // 최대 무게보다 더 무거운 아이템이라면 위에서 그대로
            if(j<w) dp[i][j] = dp[i-1][j];
            // 아니라면, 위와 j-w인 위치에서 가치를 더한 것 중 최대를
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
            }
        }
    }
    cout<< dp[n][k] << endl;
    return 0;
}
