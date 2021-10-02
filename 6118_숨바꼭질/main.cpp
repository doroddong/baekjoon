//
//  main.cpp
//  6118_숨바꼭질
//
//  Created by 이동훈 on 2020/11/04.
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
#define MAX 20001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int hide_num, hide_dist, same_cnt;

vector<int> graph[MAX];
bool visited[MAX];

int bfs(int start, int dest){
    
    queue<pair<int,int>> q;
    q.push(make_pair(start,0));
    visited[start] = true;
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_cost = q.front().second;
        q.pop();
        
        if(cur_x == dest){
            return cur_cost;
        }
        else{
            for(int i=0;i<graph[cur_x].size();i++){
                int next_x = graph[cur_x][i];
                if(!visited[next_x]){
                    visited[next_x] =true;
                    q.push(make_pair(next_x,cur_cost+1));
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=2;i<=n;i++){
        memset(visited,false,sizeof(visited));
        int cur_cost = bfs(1,i);
    }
    
    cout<< hide_num <<" "<< hide_dist<< " " << same_cnt<<endl;
    
    return 0;
}

