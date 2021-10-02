//
//  main.cpp
//  2589_보물섬
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

int map[51][51];
int dist[51][51];
int dx[] = { 0, 0 ,-1,1};
int dy[] = { -1, 1, 0,0};
int height, width;

queue<pair<int,int>> lands;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> height >> width;

  for(int i=0;i<height;i++){
    string s;
    cin >> s;
    for(int j=0;j<width;j++){
      if(s[j]=='L') {
        map[i][j]=1;
        lands.push(make_pair(i,j));
      }
      else map[i][j]=0;
    }
  }

  int max_distance =0;

  while(!lands.empty()){
    int start_land_y = lands.front().first;
    int start_land_x = lands.front().second;
    lands.pop();

    memset(dist,0,sizeof(dist));
    queue<pair<int,int>> next_land;
    next_land.push(make_pair(start_land_y,start_land_x));

    while(!next_land.empty()){
      int y = next_land.front().first;
      int x = next_land.front().second;
      next_land.pop();

      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inRange(nx,ny,width,height)!=1)  continue;
        if(map[ny][nx]==0 || (nx == start_land_x && ny==start_land_y)) continue;

        if(dist[ny][nx]==0 || dist[ny][nx]>dist[y][x]+1){
          dist[ny][nx] = dist[y][x]+1;
          next_land.push(make_pair(ny,nx));
        }
      }
    }

    for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
        max_distance = max(max_distance, dist[i][j]);
      }
    }
  }

  cout<< max_distance<< endl;
  
  return 0;
}
