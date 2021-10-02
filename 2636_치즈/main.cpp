//
//  main.cpp
//  2636_치즈
//
//  Created by 이동훈 on 2020/08/24.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
using namespace std;

int height, width;
int cheese[101][101];
bool boundary_visited[101][101];
bool out_visited[101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> boundary_cheese; //가장자리 치즈 큐
queue<pair<int,int>> outside_air;     // 외부 공기 큐

// 외부 공기와 가장자리 치즈 확인 (bfs)
void check_ouside_air_and_boundary_cheese(){
  // (0,0) 부터 탐색
  outside_air.push(make_pair(0,0));
  
  // 외부 공기 큐가 빌 때까지
  while(!outside_air.empty()){
    int x = outside_air.front().first;
    int y = outside_air.front().second;
    outside_air.pop();

    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(inRange(nx,ny,height,width)==1){
        // 외부 공기 확인
        if(cheese[nx][ny]==0 && !out_visited[nx][ny]){
          outside_air.push(make_pair(nx,ny));
          out_visited[nx][ny] = true;
        }

        // 가장자리 치즈 확인
        if(cheese[nx][ny]==1 && !boundary_visited[nx][ny]){
          boundary_cheese.push(make_pair(nx,ny));
          boundary_visited[nx][ny]=true;
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> height >> width;
  
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      cin >> cheese[i][j];
    }
  }

  int hour =0;
  int cnt=0, pre=0;
  while(1){
    // 변수 초기화
    memset(boundary_visited,false,sizeof(boundary_visited));
    memset(out_visited,false,sizeof(out_visited));

    // 외부 공기와 가장자리 치즈 확인
    check_ouside_air_and_boundary_cheese();

    // 가장자리 치즈가 0이라면 모두 녹았으므로 break;
    cnt = boundary_cheese.size();
    if(cnt ==0) break;
    // 이전 사이즈 저장
    pre =cnt;
    
    //가장자리 치즈 제거
    while(!boundary_cheese.empty()){
      int x = boundary_cheese.front().first;
      int y = boundary_cheese.front().second;
      boundary_cheese.pop();

      cheese[x][y]=0;
    }
    hour++;
  }

  cout<< hour << endl << pre;
  
  return 0;
}
