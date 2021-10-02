//
//  main.cpp
//  14502_연구소
//
//  Created by 이동훈 on 2020/09/16.
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

int n,m;
int map[8][8];
int temp[8][8];
//bool check[8][8];
bool visited[8][8];
int max_size=-1;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// 바이러스를 퍼뜨린 후 안전지대 카운트
void spread_virus_bfs(){
    
    // 저장할 임시 배열 생성
    int after_spread[n][m];
    
    // 복사
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            after_spread[i][j] = temp[i][j];
        }
    }
    
    //bfs 수행
    queue<pair<int,int>> q;
    
    // 바이러스가 있는 좌표 push
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(after_spread[i][j]==2){
                q.push(make_pair(i,j));
            }
        }
    }
    
    // bfs수행
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if(next_x<0 || next_x >= n || next_y < 0 || next_y >=m) continue;
            // 빈 칸이라면 전염하고 push
            if(after_spread[next_x][next_y] == 0){
                after_spread[next_x][next_y] =2;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
    
    // 안전지대 카운트
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(after_spread[i][j] ==0)  cnt++;
        }
    }
    max_size = max(max_size,cnt);
}

// 벽을 만드는 dfs
void make_wall_dfs(int cnt){
    if(cnt==3){
        spread_virus_bfs();
        return;
    }
    
    // 빈칸이라면 벽 생성하고 dfs 재귀 호출
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0){
                temp[i][j]=1;
                make_wall_dfs(cnt+1);
                temp[i][j]=0;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    
    // 0이라면 temp에 배열 복사 후 벽 세우고 dfs 수행
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                for(int k=0;k<n;k++){
                    for(int p=0;p<m;p++){
                        temp[k][p] = map[k][p];
                    }
                }
                temp[i][j] = 1;     // 벽 생성
                make_wall_dfs(1);
                temp[i][j]=0;       // 벽 허뭄
            }
        }
    }
    
    cout<<max_size<<endl;
  
    return 0;
}
