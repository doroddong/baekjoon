//
//  main.cpp
//  1937_욕심쟁이판다
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

int map[500][500],dp[500][500];
int n;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x,int y){
    int temp=0;
    
    if(dp[x][y] == -1){
        dp[x][y]=1;
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
        
            if(map[next_x][next_y]> map[x][y]){
                if(inRange(next_x,next_y,n,n)){
                    temp = max(temp, dfs(next_x,next_y));
                }
            }
        }
        dp[x][y] += temp;
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    int ans=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans,dfs(i,j));
        }
    }
    
    cout<<ans<<endl;
  
    return 0;
}
