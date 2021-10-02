//
//  main.cpp
//  2580_스도쿠
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
using namespace std;

int board[9][9];
bool visited[10];
vector<pair<int,int>> v;

bool check_hor(int x,int num){
  for(int i=0;i<9;i++){
    if(board[x][i]==num)  return false;
  }
  return true;
}

bool check_ver(int y,int num){
  for(int i=0;i<9;i++){
    if(board[i][y]==num)  return false;
  }
  return true;
}

bool check_square_num(int x,int y){
  int ver = x/3;
  int hor = y/3;

  return 3*ver+hor;
}

bool check_squ(int x,int y,int num){
  int ver = x/3;
  int hor = y/3;

  for(int i=3*ver;i<3*ver+3;i++){
    for(int j=3*hor;j<3*hor+3;j++){
      if(board[i][j]==num)  return false;
    }
  }
  return true;
}

void dfs(int index){

  if(index == v.size()){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<board[i][j]<<' ';
      }
      cout<<'\n';
    }
    exit(0);
  }

  for(int i=1;i<=9;i++){
    memset(visited,false,sizeof(visited));
    int x = v[index].first;
    int y = v[index].second;

    if(check_hor(x,i)&&check_ver(y,i)&&check_squ(x,y,i)){
      board[x][y] = i;
      dfs(index+1);
      board[x][y]=0;
    }
  }
}

int main(){
  memset(visited,false,sizeof(visited));
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin >> board[i][j];
      if(board[i][j]==0){
        v.push_back(make_pair(i,j));
      }
    }
  }
  dfs(0);
  return 0;
}
