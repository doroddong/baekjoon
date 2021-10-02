//
//  main.cpp
//  1405_미친 로봇
//
//  Created by 이동훈 on 2020/10/05.
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
#define MAX 30
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
double sum=0;
double fre[4];
int map[MAX][MAX];
bool visitied[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt, double cur_pro){
    
    // 끝까지 왔다면 현재 확률을 더해줌
    if(cnt==n){
        sum += cur_pro;
        return;
    }
    
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // 나아갈 수 있다면
        if(!visitied[next_x][next_y]){
            visitied[next_x][next_y] = true;
            // cnt를 증가시키고 해당 방향의 확률을 더해줌
            dfs(next_x, next_y, cnt+1, cur_pro * fre[i] );
            visitied[next_x][next_y] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<4;i++){
        cin >> fre[i];
        fre[i] /=(double)100;
    }
    
    visitied[15][15] =true;
    dfs(15,15,0,1);
    
    // 소수점 10^-9 까지 출력해야하므로 다음과 같이 출력해야함
    cout.precision(10);
    cout << fixed << sum << endl;
  
    return 0;
}

