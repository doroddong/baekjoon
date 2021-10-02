//
//  main.cpp
//  1238_파티
//
//  Created by 이동훈 on 2020/08/26.
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
#define MAX 1001
#define INF 987654321
#define endl "\n"

using namespace std;

int n,m,x;
vector<pair<int,int>> graph[MAX];
int dist[MAX];

int dijkstra(int start,int dest){
    
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    dist[start] =0;
    
    while(!pq.empty()){
        int cur_cost = - pq.top().first;
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
    return dist[dest];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> x;
    
    for(int i=0;i<m;i++){
        int from , to , dis;
        cin >> from >> to >>dis;
        graph[from].push_back(make_pair(to,dis));
    }
    
    int maximum = 0;
    for(int i=1;i<=n;i++){
        maximum = max(maximum,dijkstra(i,x)+dijkstra(x,i));
    }
    
    cout<<maximum<<endl;
    return 0;
}
