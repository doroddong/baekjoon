//
//  main.cpp
//  1167_트리의지름
//
//  Created by 이동훈 on 2020/08/24.
//  Copyright © 2020 이동훈. All rights reserved.
//

// 임의의 노드를 잡고 최대 길이인 노드를 저장하고
// 그 노드에서 다시 가장 먼 노드를 찾으면 곧 트리의 지름이다.


#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
using namespace std;

int vertex;
vector<vector<pair<int,int>>> edges;
bool visited[100001];
int diameter=0;
int end_point=0 ;

void dfs(int from,int cur_dist){
  
  if(visited[from])  return;
  visited[from] = true;

  if(diameter<cur_dist){
    diameter= max(diameter,cur_dist);
    end_point = from;
  }

  int size = edges[from].size();
  for(int i=0;i<size;i++){
    int next_from = edges[from][i].first;
    int next_dist = edges[from][i].second;
    dfs(next_from,cur_dist+next_dist);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> vertex;
  edges.resize(vertex+1);

  for(int i=0;i<vertex;i++){
    int from , to, dist;
    cin >> from ;
    while(1){
      cin >> to ;
      if(to==-1)  break;
      cin >> dist;
      edges[from].push_back(make_pair(to,dist));
    }
  }

  memset(visited,false,sizeof(visited));
  dfs(1,0);
  diameter=0;

  memset(visited,false,sizeof(visited));
  dfs(end_point,0);
  cout<< diameter<<endl;

  return 0;
}
