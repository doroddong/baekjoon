//
//  main.cpp
//  4485_녹색옷
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
#define MAX_NODE 100001
#define INF 987654321

using namespace std;

int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {1,-1,0,0};
int n;
int map[126][126];
int dist[126][126];
vector<int> answer;

// 인접행렬을 통한 다익스트라
void dijkstra(){
    // cost와 좌표 순
  priority_queue<pair<int,pair<int,int>>> pq;

  pq.push(make_pair(-map[1][1],make_pair(1,1)));
  dist[1][1]=map[1][1];

  while(!pq.empty()){
    int cur_cost = -pq.top().first;
    int cur_y = pq.top().second.first;
    int cur_x = pq.top().second.second;
    pq.pop();

    for(int i=0;i<4;i++){
      int next_x = cur_x + dir_x[i];
      int next_y = cur_y + dir_y[i];
      
      if(inRange(next_x,next_y,n,n)==1){
        int next_cost = cur_cost + map[next_y][next_x];
        if(dist[next_y][next_x]> next_cost){
          dist[next_y][next_x] = next_cost;
          pq.push(make_pair(-dist[next_y][next_x],make_pair(next_y,next_x)));
        }
      }
    }
  }
  answer.push_back(dist[n][n]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  while(1){
    cin >> n;
    if(n ==0) break;

    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin >> map[i][j];
      }
    }

    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dist[i][j]=INF;
      }
    }
    dijkstra();

  }

  for(int i=0;i<answer.size();i++){
    cout<< "Problem "<<i+1<<": "<<answer[i]<<endl;

  }

  return 0;
}
