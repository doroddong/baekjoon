//
//  main.cpp
//  2644_촌수계산
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

vector<vector<int>> family;
vector<int> dis;
vector<bool> visited;
queue<int> q;
int n, from, to, m, parent, child, cnt=0;
bool flag;

void bfs(int index){
  visited[index]=true;
  q.push(index);

  while(!q.empty()){
    int front = q.front();
    q.pop();
    
    int child_num = family[front].size();
    for(int j=0;j<child_num;j++){
      if(!visited[family[front][j]]){
        visited[family[front][j]]=true;
        dis[family[front][j]]=dis[front]+1;
        q.push(family[front][j]);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  family.resize(n+1);
  dis.resize(n+1);
  visited.resize(n+1,false);
  
  cin >> from >> to >> m;

  for(int i=0;i<m;i++){
    cin >> parent >> child;
    family[parent].push_back(child);
    family[child].push_back(parent);
  }
  bfs(from);

  if(dis[to]!=0) cout<<dis[to]<<endl;
  else  cout<<-1<<endl;
  return 0;
}
