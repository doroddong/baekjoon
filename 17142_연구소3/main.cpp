//
//  main.cpp
//  17142_연구소3
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

int map[50][50];
bool visited[50][50];
int copy_map[50][50];
int n,m,space=0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int min_ans=INF;

vector<pair<int,int>> virus;
bool selected_virus[10];

// copy_map을 초기화
void init_map(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            copy_map[i][j] =-1;
        }
    }
}

// bfs로 바이러스를 퍼뜨림
void spread_out_bfs(){
    
    queue<pair<int,int>> q;
    
    // 선택된 바이러스라면, 큐에 넣어주고 copy_map에 0으로
    for(int i=0;i<virus.size();i++){
        if(selected_virus[i]){
            q.push(make_pair(virus[i].first,virus[i].second));
            copy_map[virus[i].first][virus[i].second]=0;
        }
    }
    
    int virus_space = 0;
    int total_time =0;
    
    // bfs 수행
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if(next_x<0 || next_y <0 || next_x >= n || next_y >= n) continue;
            
            // map이 벽이 아니고 바이러스가 아직 오지 않은 공간이면
            if(map[next_x][next_y] != -1 && copy_map[next_x][next_y] ==-1){
                copy_map[next_x][next_y] = copy_map[x][y]+1;
                
                // map이 빈 공간이라면
                if(map[next_x][next_y]==0){
                    virus_space++;                          // 바이러스 공간 추가
                    total_time = copy_map[next_x][next_y];  // 총 시간 갱신
                }
                q.push(make_pair(next_x,next_y));           // 큐에 push
            }
        }
    }
    
    // 모두 퍼뜨려진다면 최소값 갱신
    if(virus_space == space){
        min_ans = min(min_ans,total_time);
    }
}

// 바이러스를 고름
void select_virus_dfs(int idx, int cnt){
    
    // m개의 바이러스를 골랐다면
    if(cnt==m){
        init_map();         //copy_map을 초기화
        spread_out_bfs();   // 바이러스 퍼뜨려서 시간 계산
        return;
        
    }
    
    // 아직 m개가 아니라면 idx부터 안 고른 거 선택
    for(int i=idx;i<virus.size();i++){
        if(selected_virus[i])   continue;
        selected_virus[i] =true;
        select_virus_dfs(i+1, cnt+1);
        selected_virus[i] = false;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            
            // 바이러스라면 vector에 좌표 저장
            if(map[i][j]==2){
                virus.push_back(make_pair(i,j));
            }
            // 벽이라면 -1로
            else if(map[i][j] ==1){
                map[i][j] = -1;
            }
            
            // 빈공간이라면 space 추가
            else{
                space++;
            }
        }
    }
    // 바이러스를 고르는 함수 dfs 시작
    select_virus_dfs(0,0);
    
    if(min_ans==INF)    min_ans = -1;
    
    cout<< min_ans <<endl;
  
    return 0;
}
