//
//  main.cpp
//  2206_벽부수고이동
//
//  Created by 이동훈 on 2020/09/24.
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
int map[1000][1000];

// 두번째 인자가 0이라면 벽을 부수지 않은 기록, 1이라면 벽을 부수고 방문한 기록
bool visited[1000][1000][2];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(){
    
    // 첫번째 pair : 좌표(x,y)
    // 두번째 pair : 벽을 부순 횟수, 거리
    queue<pair<pair<int,int>,pair<int,int>>> q;
    
    q.push(make_pair(make_pair(0,0),make_pair(0,1)));
    visited[0][0][0] = true;
    
    while(!q.empty()){
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        
        int cur_break = q.front().second.first;
        int cur_dist = q.front().second.second;
        q.pop();
        
        // 목적지라면 return
        if(cur_x== n-1 && cur_y ==m-1){
            return cur_dist;
        }
        
        for(int i=0;i<4;i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            // 범위 내의 좌표인지
            if(next_x>=0 && next_y >=0 && next_x <n && next_y <m){
                
                // 다음이 벽이라면, 벽을 부순 횟수가 0이어야하고 벽을 부수고 방문한 기록이 없으면 q에 푸시
                if(map[next_x][next_y]==1 && cur_break == 0 && !visited[next_x][next_y][1]){
                    visited[next_x][next_y][1] = true;
                    q.push(make_pair(make_pair(next_x,next_y),make_pair(cur_break+1,cur_dist+1)));
                }
                
                // 다음이 벽이 아니라면, 벽을 부시지 않고 방문한 기록이 없으면 q에 푸시
                if(map[next_x][next_y]==0 && !visited[next_x][next_y][cur_break]){
                    visited[next_x][next_y][cur_break] = true;
                    q.push(make_pair(make_pair(next_x,next_y),make_pair(cur_break,cur_dist+1)));
                    
                }
            }
        }
    }
    return -1;
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            map[i][j] = s[j]-'0';
        }
    }
    
    int result = bfs();
    cout<< result <<endl;
  
    return 0;
}
