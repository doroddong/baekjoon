//
//  main.cpp
//  1753_최단경로
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
#include <cmath>
#include <cstdio>

#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 20001
#define INF 987654321

using namespace std;

int v,e,start;
int dist[MAX];
vector<pair<int,int>> graph[MAX];

void dijkstra(int start){
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0,start));
  dist[start]=0;

  while(!pq.empty()){
    int cur_cost = -pq.top().first;
    int cur_vertex = pq.top().second;
    pq.pop();

    for(int i=0;i<graph[cur_vertex].size();i++){
      int next_vertex = graph[cur_vertex][i].first;
      int next_cost = graph[cur_vertex][i].second;

      if(dist[next_vertex] > cur_cost + next_cost){
        dist[next_vertex] = cur_cost + next_cost;
        pq.push(make_pair(-dist[next_vertex],next_vertex));
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> v >> e >> start;
  
  for(int i=0;i<e;i++){
    int from , to, dis;
    cin >> from >> to >> dis;
    graph[from].push_back(make_pair(to,dis));
  }

  for(int i=1;i<=v;i++) dist[i] = INF;

  dijkstra(start);


  for(int i=1;i<=v;i++){
    if(dist[i]==INF)  cout<<"INF"<<endl;
    else  cout<<dist[i]<<endl;
  }
  
  return 0;
}
