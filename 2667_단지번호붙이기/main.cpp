//
//  main.cpp
//  2667_단지번호붙이기
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int map[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    
    queue<pair<int,int>> q;
    
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                
                if(map[next_x][next_y])
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
        
        for(int j=0;i<s.size();i++){
            map[i][j] = s[j] - '0';
        }
    }
    
    for(int i=0;i<n;i+++){
        for(int j=0;j<n;j++){
            bfs(i,j);
        }
    }
    return 0;
}

