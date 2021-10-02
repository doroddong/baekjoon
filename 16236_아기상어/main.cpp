//
//  main.cpp
//  16236_아기상어
//
//  Created by 이동훈 on 2020/08/28.
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
#define outRange(x,y,max_x,max_y) ((x<0) || (x>=max_x) || (y<0) || (y>=max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX_MAP 21
#define MAX_DIST 401
#define INF 987654321
#define endl "\n"

/*
 시간 복잡도 : O(n^4)
 공간 복잡도 : O(n^2)
 사용한 알고리즘 : BFS (완전탐색)
    BFS 를 선택한 이유
        1. 최단 경로 찾기
        2. BFS는 모든 간선의 가중치가 1일때 유용
        3. BFS의 시간 복잡도 : 1) 인접리스트를 사용한 경우 O(v+e) 2) 인접행렬을 사용한 경우 O(v^2)
 
 정점의 수 : n^2
 간선의 수 : 4 * n^2
 => 총 O(n^2)
 
 
 
 */

int map[MAX_MAP][MAX_MAP], dist[MAX_MAP][MAX_MAP];
int shark_size=2, eat_cnt=0;
int n, shark_x, shark_y, answer, min_dist, min_x, min_y;

int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,1,-1};

using namespace std;

// 단계마다 정보 초기화
void init_dist(){
    min_dist = MAX_DIST;
    min_x = MAX_MAP;
    min_y = MAX_MAP;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = -1;
            
        }
    }
}

// BFS 완전 탐색
void bfs(int x, int y){
    
    // 큐 초기화
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    dist[x][y] = 0;
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = cur_x + dir_x[i];
            int next_y = cur_y + dir_y[i];
            
            // 지도 밖일 경우 건너뜀
            if(outRange(next_x,next_y,n,n))   continue;
            // 1. 이미 방문 2. 상어의 크기보다 큰 물고기일 경우 건너뜀
            if(dist[next_x][next_y] !=-1 || map[next_x][next_y] > shark_size)   continue;
            
            // 거리를 갱신
            dist[next_x][next_y] = dist[cur_x][cur_y]+1;
            
            // 먹을 수 있는 물고기일 경우
            if(map[next_x][next_y] < shark_size && map[next_x][next_y] !=0){
                // 현재 물고기까지의 거리가 더 짧은 경우
                if(min_dist > dist[next_x][next_y]){
                    min_x = next_x;
                    min_y = next_y;
                    min_dist = dist[next_x][next_y];
                }
                // 거리가 같은 경우 위 -> 왼쪽을 찾음
                else if(min_dist == dist[next_x][next_y]){
                    if(min_x > next_x){
                        min_x = next_x;
                        min_y = next_y;
                    }
                    else if (min_x == next_x){
                        if(min_y > next_y){
                            min_x = next_x;
                            min_y = next_y;
                        }
                    }
                }
            }
            // 다음 위치를 큐에 넣어줌
            q.push(make_pair(next_x, next_y));
        }
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            
            // 상어일 경우, 상어 위치 갱신 후 지도상에서 0으로 비워둠
            if(map[i][j] == 9){
                shark_x = i;
                shark_y = j;
                map[shark_x][shark_y] =0;
            }
        }
    }
    
    while(true){
        // BFS 를 위한 정보 초기화
        init_dist();
        // bfs 완전 탐색
        bfs(shark_x,shark_y);
        
        // 먹을 수 있는 물고기를 찾은 경우
        if(min_x != MAX_MAP && min_y!=MAX_MAP){
            // 이동 시간 넣어줌
            answer += dist[min_x][min_y];
            
            // 먹은 물고기 수 증가
            eat_cnt++;
            
            // 먹은 물고기 수와 상어의 크기가 같다면 크기를 1 증가, 먹은 물고기 수 초기화
            if(eat_cnt == shark_size){
                shark_size++;
                eat_cnt=0;
            }
            // 먹은 물고기의 위치를 0으로 갱신
            map[min_x][min_y]=0;
            
            // 상어의 위치를 갱신
            shark_x = min_x;
            shark_y = min_y;
        }
        
        // 먹을 수 있는 고기가 없는 경우 반복문 끝
        else{
            break;
        }
    }
    
    cout<< answer << endl;
    
    return 0;
}
