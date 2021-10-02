//
//  main.cpp
//  1799_비숍
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

vector<pair<int,int>> black_space;
vector<pair<int,int>> white_space;

int n;
int board[10][10];
bool check1[20];    // 오른쪽에서 왼쪽 아래로 가는 대각선
bool check2[20];    // 왼쪽에서 오른쪽 아래로 가는 대각선
int ans[2];

int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,-1,1};

// color : 0은 검은색, 1은 흰색
// for문 없이 재귀함수로만 구현하기
void dfs(int cnt, int x, int y, int color){
    if(x>=n){
        y++;
        if(x%2==0) x=1;
        else x=0;
    }
    
    if(y>=n){
        if(cnt>ans[color]) ans[color] = cnt;
        return;
    }
    
    if(board[y][x] && !check1[x+y+1] && !check2[x-y+n]){
        check1[x+y+1] =true;
        check2[x-y+n] = true;
        dfs(cnt+1, x+2, y,color);
        check1[x+y+1] =false;
        check2[x-y+n] = false;
    }
    dfs(cnt,x+2,y,color);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    
    dfs(0,0,0,0);   //검은색 체스판
    dfs(0,1,0,1);   //흰색 체스판
    
    cout<<ans[0]+ans[1]<<endl;

    
    return 0;
}
