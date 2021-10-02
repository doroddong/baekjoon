//
//  main.cpp
//  2583_영역구하기
//
//  Created by 이동훈 on 2020/11/02.
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
#define MAX 101
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

bool map[MAX][MAX];
int m, n, k;
int area_cnt=0;
int cur_area=0;
vector<int> area;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    map[x][y] = true;
    cur_area++;
    
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x>=0 && next_x<m && next_y >=0 && next_y<n && !map[next_x][next_y]){
            dfs(next_x,next_y);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n >> k;
    
    for(int i=0;i<k;i++){
        int lower_x, lower_y, upper_x, upper_y;
        cin >> lower_x >> lower_y >> upper_x >> upper_y;
        
        for(int j=lower_y;j<upper_y;j++){
            for(int p=lower_x;p<upper_x;p++){
                map[j][p] = true;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!map[i][j]){
                area_cnt++;
                cur_area=0;
                dfs(i,j);
                area.push_back(cur_area);
            }
        }
    }
    sort(area.begin(),area.end());
    cout<< area_cnt<<endl;
    
    for(int i=0; i<area.size();i++){
        cout<< area[i] << " ";
    }
    cout<<endl;
    
    return 0;
}

