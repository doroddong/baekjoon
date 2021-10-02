//
//  main.cpp
//  2668_숫자고르기
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

const int MAX = 101;

int N;
int cnt;

int node[MAX];
bool visited[MAX];
bool cycle[MAX];

bool dfs(int start, int cur){
  if(visited[cur]) return false;

  visited[cur] = true;
  
  if(start == cur || dfs(start,node[cur])){
    cnt++;
    cycle[cur] =true;
    return true;
  }
  return false;
}

int main(){
  cin >> N;

  for(int i=1;i<=N;i++) cin>>node[i];

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      visited[j]=cycle[j];
    }
    dfs(i,node[i]);
  }
  cout<< cnt<<endl;
  for(int i=1;i<=N;i++){
    if(cycle[i])  cout<< i <<endl;
  }
  return 0;
}
