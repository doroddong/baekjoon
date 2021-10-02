//
//  main.cpp
//  1987_알파벳
//
//  Created by 이동훈 on 2020/09/15.
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

int r,c;
char board[21][21];
bool check[26];     //알파벳의 사용 여부 체크

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<char> route;
int max_route = -1;

void dfs(int x,int y,int dist){
    
    max_route = max(max_route,dist);
    
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x<1 || next_x >r || next_y <1 || next_y >c) continue;
        
        
        if(check[board[next_x][next_y]-'A']==false){
            check[board[next_x][next_y]-'A'] = true;
            dfs(next_x,next_y,dist+1);
            check[board[next_x][next_y]-'A'] = false;
        }
        
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> r >> c;
    
    for(int i=1;i<=r;i++){
        string s;
        cin >> s;
        
        for(int j=0;j<c;j++){
            board[i][j+1] = s[j];
        }
    }
    
    check[board[1][1] - 'A'] = true;    // 사용된 문자를 체크
    dfs(1,1,1);
    
    cout<<max_route<<endl;
    
  
    return 0;
}
