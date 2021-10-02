//
//  main.cpp
//  2176_합리적인이동경로
//
//  Created by 이동훈 on 2020/09/09.
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

bool selected[MAX];
int n,m,cnt=0;

void dfs(int x,vector<vector<int>> graph){
    
    bool is_2=false;
    
    for(int i=0;i<graph[x].size();i++){
        int to = graph[x][i];
        
        if(to==2){
            cnt++;
            is_2 = true;
            return;
        }
    }
    
    if(!is_2){
        for(int i=0;i<graph[x].size();i++){
            int to = graph[x][i];
            
            if(!selected[to]){
                selected[to] = true;
                dfs(to,graph);
                selected[to] = false;
            }
            
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);;
    for(int i=0;i<m;i++){
        int from , to , cost;
        cin >> from >> to >> cost;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    selected[1] =true;
    dfs(1,graph);
    
    cout<<cnt<<endl;
  
    return 0;
}
