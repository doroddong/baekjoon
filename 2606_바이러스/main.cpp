//
//  main.cpp
//  2606_바이러스
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

vector<vector<int>> edges;
vector<bool> visited;
int computer_num, edge_num;
int ans=0;

void dfs(int index){
  ans++;
  visited[index]=true;

  for(int i=0;i<edges[index].size();i++){
    if(!visited[edges[index][i]]) dfs(edges[index][i]);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> computer_num >> edge_num;
  edges.resize(computer_num+1);
  visited.resize(computer_num+1,false);
  for(int i=1;i<=edge_num;i++){
    int from , to;
    cin >> from >> to;

    edges[from].push_back(to);
    edges[to].push_back(from);
  }

  dfs(1);

  cout<<ans-1;
  return 0;
}
