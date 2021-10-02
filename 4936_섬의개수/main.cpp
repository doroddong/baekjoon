//
//  main.cpp
//  4936_섬의개수
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
#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
using namespace std;

int map[51][51];
int map_width, map_height, land_num=0;

int dir_x[8] = {0,1,1,1,0,-1,-1,-1};
int dir_y[8] = {1,1,0,-1,-1,-1,0,1};

void search(int x,int y){
  map[x][y]=0;
  for(int i=0;i<8;i++){
    int dx = x + dir_x[i];
    int dy = y + dir_y[i];

    if(1<=dx && dx<=map_height && 1<=dy && dy <=map_width){
      if(map[dx][dy]==1)  {
        // cout<<"통과 "<<x<<" "<<y<<"--> "<<dx<<" "<<dy<<" map : "<<map[dx][dy]<<endl;
        search(dx,dy);
      }
    // else{
    //   cout<<"못 통과 "<<x<<" "<<y<<"--> "<<dx<<" "<<dy<<" map : "<<map[dx][dy]<<endl;
    // }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  vector<int> land_list;

  
  cin >> map_width >> map_height;
  while(map_width!=0 && map_height!=0){
    land_num =0;
    memset(map,0,sizeof(map));

    for(int i=1;i<=map_height;i++){
      for(int j=1;j<=map_width;j++){
        cin >> map[i][j];
      }
    }

    for(int i=1;i<=map_height;i++){
      for(int j=1;j<=map_width;j++){
        if(map[i][j]==1){
          search(i,j);
          land_num++;
        }
      }
    }
    land_list.push_back(land_num);
    cin >> map_width >> map_height;
  }
  
  for(int i=0;i<land_list.size();i++)  cout<<land_list[i]<<"\n";

  return 0;
}
