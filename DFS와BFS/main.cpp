//
//  main.cpp
//  DFS와BFS
//
//  Created by 이동훈 on 2020/11/07.
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

typedef long long ll;
typedef pair<int,int> pii;

int n, m, v;
int visited[MAX];
vector<int> graph[MAX];
vector<int> dfs_route;
vector<int> bfs_route;

void init(){
    memset(visited,false,sizeof(visited));
}

void dfs(int cur){
    dfs_route.push_back(cur);
    visited[cur] = true;
    
    for(int i=0;i<graph[cur].size();i++){
        int next_x = graph[cur][i];
        if(!visited[next_x])    dfs(next_x);
    }
}

void bfs(int start){
    
    queue<int> q;
    visited[start] = true;
    bfs_route.push_back(start);
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<graph[cur].size();i++){
            int next_x = graph[cur][i];
            if(!visited[next_x]){
                visited[next_x] =true;
                bfs_route.push_back(next_x);
                q.push(next_x);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> v;
    
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    init();
    dfs(v);
    
    init();
    bfs(v);
    
    for(int i=0;i<dfs_route.size();i++){
        cout<< dfs_route[i] << " ";
    }
    cout<<endl;
    
    for(int i=0;i<bfs_route.size();i++){
        cout << bfs_route[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}

