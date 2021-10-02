//
//  main.cpp
//  3187_양치기꿍
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

int survive_v=0, part_v;
int survive_k=0, part_k;
int dir_x[4] = {-1,1,0,0};
int dir_y[4] = {0,0,1,-1};
int width, height;
char map[250][250];
bool visited[250][250];

void bfs(int x, int y){
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  visited[x][y] = true;

  part_v=0;
  part_k=0;
  
  while(!q.empty()){
    int cur_x = q.front().first;
    int cur_y = q.front().second;
    q.pop();

    for(int i=0;i<4;i++){
      int dx = cur_x+ dir_x[i];
      int dy = cur_y+ dir_y[i];

      if((dx<0||dy<0||width<=dx||dy>=height)
      || visited[dx][dy]
      || map[dx][dy]=='#')  continue;

      if(map[dx][dy]=='k')  {
        part_k++;
        q.push(make_pair(dx,dy));
        visited[dx][dy]=true;
      }
      else if(map[dx][dy]=='v'){
        part_v++;
        q.push(make_pair(dx,dy));
        visited[dx][dy]=true;
      }
      else{
        q.push(make_pair(dx,dy));
        visited[dx][dy]=true;
      }
    }
  }
  if(part_k>part_v)
  {
    survive_k+= part_k;
  }
  else
  {
    survive_v+=part_v;
  }
  
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> width >> height;

  for(int i=0;i<width;i++){
    for(int j=0;j<height;j++){
      cin >> map[i][j];
    }
  }
  memset(visited,false,sizeof(visited));
  for(int i=0;i<width;i++){
    for(int j=0;j<height;j++){
      if(!visited[i][j]){
        bfs(i,j);
      }
    }
  }
  
  cout<< survive_k<<" " << survive_v<<endl;
  
  return 0;
}
