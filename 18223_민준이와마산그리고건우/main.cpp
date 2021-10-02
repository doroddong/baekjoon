//
//  main.cpp
//  18223_민준이와마산그리고건우
//
//  Created by 이동훈 on 2020/08/25.
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

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 5001
#define INF 987654321
#define endl "\n"

using namespace std;

int v,e,p;
vector<pair<int,int>> graph[MAX];
int dist[MAX];

int dijkstra(int start,int des){
    
    for(int i=1;i<=v;i++){
        dist[i]=INF;
    }
    
    priority_queue<pair<int,int>> pq;
    dist[start]=0;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        int cur_cost = - pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();
        
        for(int i=0;i<graph[cur_vertex].size();i++){
            int next_vertex = graph[cur_vertex][i].first;
            int next_cost = graph[cur_vertex][i].second;
            
            if(dist[next_vertex]> cur_cost + next_cost){
                dist[next_vertex] = cur_cost + next_cost;
                pq.push(make_pair(-dist[next_vertex],next_vertex));
            }
        }
    }
    
    return dist[des];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> v >> e >> p;
    
    for(int i=0;i<e;i++){
        int from , to , dis;
        cin >> from >> to >> dis;
        graph[from].push_back(make_pair(to,dis));
        graph[to].push_back(make_pair(from,dis));
    }

    int minimum = dijkstra(1,v);
    int transfer = dijkstra(1, p) + dijkstra(p, v);
    
    cout<< (minimum == transfer ? "SAVE HIM" : "GOOD BYE") <<endl;

    return 0;
}
