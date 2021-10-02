//
//  main.cpp
//  7562_나이트의이동
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
#define MAX 301
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


vector<int> v;
int move_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int t;
bool visited[MAX][MAX];

int bfs(pair<int,int> cur, pair<int,int> des,int map_size){
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(cur.first,cur.second),0));
    visited[cur.first][cur.second] = true;
    
    while(!q.empty()){
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int move_cnt = q.front().second;
        q.pop();
        
        if(cur_x== des.first && cur_y == des.second) {
            return move_cnt;
        }
        
        else{
            for(int i=0;i<8;i++){
                int next_x = cur_x + move_x[i];
                int next_y = cur_y + move_y[i];
                
                if(next_x>=0 && next_x<map_size && next_y >=0 && next_y <map_size){
                    if(!visited[next_x][next_y]){
                        visited[next_x][next_y] = true;
                        q.push(make_pair(make_pair(next_x, next_y),move_cnt+1));
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    for(int i=0;i<t;i++){
        memset(visited,false,sizeof(visited));
        int map_size;
        cin >> map_size;
        
        pair<int,int> cur_pair, des_pair;
        cin >> cur_pair.first >> cur_pair.second;
        cin >> des_pair.first >> des_pair.second;
        
        
        int min_cnt = bfs(cur_pair, des_pair,map_size);
        v.push_back(min_cnt);
    }
    
    for(int i=0;i<v.size();i++){
        cout<< v[i]<<endl;
    }

    return 0;
}

