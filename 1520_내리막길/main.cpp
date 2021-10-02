//
//  main.cpp
//  1520_내리막길
//
//  Created by 이동훈 on 2020/09/20.
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

int m,n;
int map[500][500];
int dp[500][500];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


// dp와 dfs를 동시에 사용하기 위해서는 이미 탐색했던 길인지, 처음 가는 길인지 판단할 수 있어야한다.
// 따라서, dp배열의 초기값을 -1로 설정하고 탐색하려는 지점의 dp 값이 초기값이라면 0으로 바꿔준 후 dfs를 수행
// 초기값이 아니라 탐색을 한 지점이라면 바로 그 값을 반환한다.
int dfs_dp(int x,int y){
    
    if(x == m-1 && y ==n-1) return 1;   // 끝 지점에 도착했다면
    
    // 처음 가는 길이라면
    else if(dp[x][y] == -1){
        dp[x][y]=0;                     //dp값을 조정해주고 탐색
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if(map[x][y] > map[next_x][next_y] &&next_x>=0 && next_y>=0 && next_x < m && next_y < n){
                dp[x][y] += dfs_dp(next_x,next_y);
            }
        }
    }
    
    return dp[x][y];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            // dp 와 dfs를 동시에 사용하기 위해서 이미 탐색했던 길인지 처음가는 길인지 판단하기 위해
            dp[i][j] =-1;
        }
    }
    
    cout<<dfs_dp(0,0)<<endl;
    
    return 0;
}
