//
//  main.cpp
//  4179_불!
//
//  Created by 이동훈 on 2020/09/22.
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

int r,c,min_time=-1;
char map[1000][1000];
bool visited[1000][1000];
queue<pair<int,int>> jq;
queue<pair<int,int>> fire_q;

int dx[4] = { -1,0,1,0};
int dy[4] = { 0,1,0,-1};

int bfs(){
    int result = 0;
    
    while(!jq.empty()){
        
        int fire_size = fire_q.size();
        
        for(int i=0;i<fire_size;i++){
            int x = fire_q.front().first;
            int y = fire_q.front().second;
            fire_q.pop();
            
            for(int i=0;i<4;i++){
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                
                if(next_x<0 || next_y < 0 || next_x>=r || next_y >= c) continue;
                if(map[next_x][next_y] == '.' || map[next_x][next_y] == 'J'){
                    map[next_x][next_y] ='F';
                    fire_q.push(make_pair(next_x,next_y));
                }
            }
        }
        
        int jq_size = jq.size();
        
        for(int i=0;i<jq_size;i++){
            int x = jq.front().first;
            int y = jq.front().second;
            jq.pop();
            
            if((x==0 || x== r-1) || (y==0 || y== c-1))  {
                return result + 1;
            }
            
            for(int i=0;i<4;i++){
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                
                if(map[next_x][next_y] == '#' || map[next_x][next_y] == 'F')    continue;
                if(next_x>=0 && next_x <r && next_y >= 0 && next_y<c && !visited[next_x][next_y]){
                    visited[next_x][next_y] = true;
                    jq.push(make_pair(next_x,next_y));
                }
            }
        }
        result++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> r >> c;
    
    for(int i=0;i<r;i++){
        string s;
        cin >> s;
        for(int j=0;j<c;j++){
            map[i][j] = s[j];
            if(map[i][j] == 'J'){
                jq.push(make_pair(i,j));
            }
            if(map[i][j] == 'F'){
                fire_q.push(make_pair(i,j));
            }
        }
    }
    
    int ans = bfs();
    
    if(ans == -1)  cout<< "IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
  
    return 0;
}
