//
//  main.cpp
//  13913_숨바꼭질4
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

int n,k;
bool visited[MAX];
int parent[MAX];
vector<int> path;
int cnt=0;

int bfs(){
    
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    visited[n]=true;
    
    while(!q.empty()){
        int cur_value = q.front().first;
        int cur_sec = q.front().second;
        q.pop();
        
        if(cur_value == k){
            int temp = cur_value;
            while(temp!=n){
                path.push_back(temp);
                temp = parent[temp];
            }
            path.push_back(n);
            return cur_sec;
        }
        
        if(cur_value+1 <MAX && !visited[cur_value+1]){
            visited[cur_value+1]=true;
            parent[cur_value+1] = cur_value;
            q.push(make_pair(cur_value+1,cur_sec+1));
        }
        
        if(cur_value-1>=0 && !visited[cur_value-1]){
            visited[cur_value-1]=true;
            parent[cur_value-1] = cur_value;
            q.push(make_pair(cur_value-1,cur_sec+1));
        }
        
        if(2 *cur_value < MAX && !visited[2*cur_value]){
            visited[2*cur_value] = true;
            parent[2*cur_value] = cur_value;
            q.push(make_pair(2*cur_value,cur_sec+1));
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    cout<< bfs() <<endl;
    
    
    for(int i=path.size()-1;i>=0;i--){
        cout << path[i]<<" ";
    }
    cout<<endl;

  
    return 0;
}
