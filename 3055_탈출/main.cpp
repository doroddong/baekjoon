//
//  main.cpp
//  3055_탈출
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

int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {-1,1,0,0};

int r,c;
queue<pair<int,int>> amurensis;
queue<pair<int,int>> water;
char map[51][51];
bool visited[51][51];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> r >> c;
    
    // 입력을 받고 두더지 위치와 물의 위치를 큐에 저장
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin >> map[i][j];
      if(map[i][j]=='S'){
        amurensis.push(make_pair(i,j));
      }
      if(map[i][j]=='*'){
        water.push(make_pair(i,j));
      }
    }
  }
  
  int min =0;
  bool flag = false;
    
    // 두더지가 비어있을 때까지
  while(!amurensis.empty()){
    int water_size = water.size();

    // 물의 위치 개수만큼 반복
    for(int i=0;i<water_size;i++){
      int cur_y = water.front().first;
      int cur_x = water.front().second;
      water.pop();

      for(int j=0;j<4;j++){
        int dy = cur_y + dir_y[j];
        int dx = cur_x + dir_x[j];
          
        if(inRange(dy,dx,r,c)){
          // 비어있는 곳이라면 물을 퍼뜨리고 큐에 푸시
          if(map[dy][dx]=='.'){
            map[dy][dx]='*';
            water.push(make_pair(dy,dx));
          }
        }
      }
    }
      
      // 두더지 큐 사이즈 계산하고 반복
    int amurensis_size = amurensis.size();

    for(int i=0;i<amurensis_size;i++){
      int cur_y = amurensis.front().first;
      int cur_x = amurensis.front().second;
      amurensis.pop();
        
        // 목적지라면 flag를 true로 하고 break
      if(map[cur_y][cur_x]=='D')  {
        flag = true;
        break;
      }

      for(int j=0;j<4;j++){
        int dy = cur_y + dir_y[j];
        int dx = cur_x + dir_x[j];

        if(inRange(dy,dx,r,c)){
            //이동할 수 있다면 true로 하고 큐에 푸시
          if(map[dy][dx]!='*' && map[dy][dx]!='X'&& !visited[dy][dx]){
            visited[dy][dx]= true;
            amurensis.push(make_pair(dy,dx));
          }
        }
      }
    }
      // flag가 true라면 break;
    if(flag)  {
      break;
    }
    min++;
  }

  if(flag)  cout<<min<<endl;
  else  cout<<"KAKTUS"<<endl;

  
  return 0;
}
