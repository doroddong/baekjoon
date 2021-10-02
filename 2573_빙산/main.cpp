//
//  main.cpp
//  2573_빙산
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
#define endl "\n"
#define inRange(x,y,max_x,max_y) ((1<=x) && (x<max_x-1) && (1<=y) && (y<max_y-1))
using namespace std;

int n,m;
int iceberg[301][301];
int adjacent[301][301];
bool visited[301][301];
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};
int cnt=0;

vector<pair<int,int>> v;

void dfs(int x,int y){
  visited[x][y] = true;

  for(int i=0;i<4;i++){
    int dx = x + dir_x[i];
    int dy = y + dir_y[i];

    if(inRange(dx,dy,m,n)==1){
      if(!visited[dx][dy] && iceberg[dx][dy]>0) dfs(dx,dy);
    }
  }
}

bool calculate_split(){
  memset(visited,false,sizeof(visited));
  cnt=0;

  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      if(!visited[i][j] && iceberg[i][j]>0) {
        cnt++;
        if(cnt==2)  return true;
        dfs(i,j);
      }
    }
  }
  return false;
}

void after_year(int year){
  bool is_splited = calculate_split();
  if(is_splited)  {
    cout<<year<<'\n';
    return;
  }
  
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      int zero_cnt =0;
      if(iceberg[i][j]!=0){
        for(int k=0;k<4;k++){
          int dx = j + dir_x[k];
          int dy = i + dir_y[k];
          if(inRange(dx,dy,m,n)==1 && iceberg[dy][dx]==0)  zero_cnt++;
        }
      }
      adjacent[i][j]=zero_cnt;
    }
  }
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      iceberg[i][j]=max(iceberg[i][j]-adjacent[i][j],0);
    }
  }
  
  after_year(year+1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> iceberg[i][j];
    }
  }

  after_year(0);
  
  return 0;
}
