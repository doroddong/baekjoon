//
//  main.cpp
//  10026_적록색약
//
//  Created by 이동훈 on 2020/10/03.
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

int n;
char map[100][100];
int no_ans=0, yes_ans=0;
bool visited[100][100];

int dx[4] = { 1, 0 , -1, 0};
int dy[4] = { 0, 1, 0, -1};


// 적록색약이 없는 사람
void no_dfs(int x, int y,char cur){
    
    visited[x][y] = true;
    
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x<0 || next_y <0 || next_x >=n || next_y >= n)  continue;
        
        // cur과 next과 다르다면 무시, 그게 아니고 visited도 false라면 dfs 수행
        if(map[next_x][next_y] != cur)  continue;
        else {
            if(!visited[next_x][next_y])    no_dfs(next_x,next_y,map[next_x][next_y]);
        }
    }
}

// 적록색약이 있는 사람
void yes_dfs(int x,int y,char cur){
    visited[x][y] = true;
    
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x<0 || next_y <0 || next_x >=n || next_y >= n)  continue;
        
        // 서로 같다면 dfs 수행
        if(cur !='B'){
            if(map[next_x][next_y] != 'B' && !visited[next_x][next_y]){ yes_dfs(next_x,next_y,map[next_x][next_y]);
            }
        }
        else{
            if(map[next_x][next_y] == 'B' && !visited[next_x][next_y]) {
                yes_dfs(next_x,next_y,map[next_x][next_y]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j= 0 ; j<n;j++){
            map[i][j] = s[j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            if(!visited[i][j]){
                no_ans++;
                no_dfs(i,j,map[i][j]);
            }
        }
    }
    
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            if(!visited[i][j]){
                yes_ans++;
                yes_dfs(i,j,map[i][j]);
            }
        }
    }
    
    cout << no_ans << " " << yes_ans << endl;
    
    return 0;
}

