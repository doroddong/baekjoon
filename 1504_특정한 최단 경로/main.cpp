//
//  main.cpp
//  1504_특정한 최단 경로
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
#define MAX_NODE 100001
#define INF 987654321
#define endl "\n"

using namespace std;

int n, e;
vector<pair<int,int>> graph[801];
int dist[801];

void dijkstra(int start){
    
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    
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
    
    cin >> n >> e;
    
    for(int i=0;i<e;i++){
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].push_back(make_pair(to,dis));
        graph[to].push_back(make_pair(from,dis));
    }
    
    int vertex1, vertex2;
    cin >> vertex1 >> vertex2;
    
    dijkstra(vertex1);
    int common = dist[vertex2];
    
    dijkstra(1);
    int first = dist[vertex1];
    int second = dist[vertex2];
    
    dijkstra(vertex2);
    first +=dist[n];
    
    dijkstra(vertex1);
    second+=dist[n];
    
    if(common ==INF){
        cout<<-1<<endl;
    }
    else if(first<second){
        if(first ==INF){
            cout<<-1<<endl;
        }
        else{
            cout<<first+common<<endl;
        }
    }
    else{
        if(second==INF){
            cout<<-1<<endl;
        }
        else{
            cout<<second+common<<endl;
        }
    }
  
    return 0;
}
