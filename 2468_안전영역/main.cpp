//
//  main.cpp
//  2468_안전영역
//
//  Created by 이동훈 on 2020/11/04.
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
#define MAX 100
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int map[MAX][MAX];
bool sink[MAX][MAX];

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

int max_cnt = 1;
int cur_cnt;

void dfs(int x, int y){
    sink[x][y] = true;
    
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x>=0 && next_x<n && next_y>=0 && next_y<n){
            if(!sink[next_x][next_y])   dfs(next_x,next_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    int max_height = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            max_height = max(max_height,map[i][j]);
        }
    }
    
    for(int i=1;i<max_height;i++){
        cur_cnt = 0;
        memset(sink,false,sizeof(sink));
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(map[j][k]<=i){
                    sink[j][k] = true;
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(!sink[j][k]){
                    cur_cnt++;
                    dfs(j,k);
                }
            }
        }
        max_cnt  = max(max_cnt, cur_cnt);
    }
    
    cout<< max_cnt <<endl;
    
    return 0;
}

