//
//  main.cpp
//  14503_로봇청소기
//
//  Created by 이동훈 on 2020/08/30.
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
#define MAX 51
#define INF 987654321
#define endl "\n"

using namespace std;

int n, m, r, c, d;
int map[MAX][MAX], visited[MAX][MAX];
int cnt=0;
/*
 북 : 0
 동 : 1
 남 : 2
 서 : 3
*/

// 바라보는 방향 : 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 바라보는 방향에 따란 후진
int back_dx[4] = {1, 0, -1, 0 };
int back_dy[4] = {0, -1, 0, 1 };


void dfs(int x, int y, int dir){
    if(map[x][y]==1) return;
    
    if(map[x][y] ==0){
        map[x][y]=2;
        cnt++;
    }
    
    for(int i=0;i<4;i++){
        // 북(0) -> 서(3) , 동(1) -> 북(0), 남(2) -> 동(1), 서(3) -> 남(2)
        int next_dir = dir -1 < 0 ? 3 : dir-1;
        int next_x = x + dx[next_dir];
        int next_y = y + dy[next_dir];
        
        // 빈칸 이면 청소
        if(map[next_x][next_y]==0){
            dfs(next_x, next_y, next_dir);
            return;
        }
        // 청소 했거나 벽이면 방향만
        else {
            dir = next_dir;
        }
    }
    // 검사 끝
    
    // 네 방향 모두 청소했거나 벽이면 방향을 유지한채로 후진
    int next_x = x + back_dx[dir];
    int next_y = y + back_dy[dir];
    
    dfs(next_x,next_y, dir);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    
    dfs(r,c,d);
    
    cout<< cnt<< endl;
    return 0;
}
