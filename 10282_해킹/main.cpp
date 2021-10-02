//
//  main.cpp
//  10282_해킹
//
//  Created by 이동훈 on 2020/09/24.
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// 테스트 케이스
int t;
int dist[10001];

// n : 노드의 수, start : 해킹 당한 노드(시작점), graph
void dijkstra(int n, int start, vector<pair<int,int>> graph[])
{
    // dist 초기화
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    
    // 다익스트라 수행
    priority_queue<pair<int,int>> pq;
    
    pq.push(make_pair(0,start));
    dist[start] = 0;
    
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
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    // 테스트 케이스만큼 반복
    for(int i=0;i<t;i++){
        int n, d, c;
        cin >> n >> d >> c;
        
        // graph 선언
        vector<pair<int,int>> graph[n+1];
        
        // 의존성 만큼 반복
        // from -> to 인 부분만 그래프 생성 (상호작용 X)
        for(int j=0;j<d;j++){
            int to,from,cost;
            cin >> to >> from >>cost;
            
            graph[from].push_back(make_pair(to,cost));
        }
        
        // 다익스트라 수행
        dijkstra(n,c, graph);
        
        int cnt = 0;
        int time = -1;
        // 노드의 수만큼 반복
        for(int j=1;j<=n;j++){
            // 거쳐간 노드라면
            if(dist[j]!=INF)    {
                //카운트 증가, 가장 큰 시간 저장
                cnt++;
                time = max(time,dist[j]);
            }
        }
        
        cout<< cnt <<" "<<time<<endl;
    }
    
  
    return 0;
}
