//
//  main.cpp
//  15686_치킨배달
//
//  Created by 이동훈 on 2020/08/30.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 50
#define INF 987654321
#define endl "\n"

using namespace std;

int n, m;
int map[MAX][MAX];
bool selected[13];
int min_dist =INF;
vector<pair<int,int>> chicken, home;


void dfs(int idx, int select){
    if(select == m){
        int temp_dist =0;
        
        // 집과 치킨집 사이의 최소 거리 계산
        for(int i=0;i<home.size();i++){
            int dist = INF;
            for(int j=0;j<chicken.size();j++){
                if(selected[j])  {
                    dist = min(dist, abs(home[i].first- chicken[j].first)+ abs(home[i].second - chicken[j].second));
                }
            }
            temp_dist += dist;
        }
        // 최단 거리라면 갱신
        min_dist= min(min_dist, temp_dist);
        return;
    }
    
    //오버 플로우 방지
    if(idx == chicken.size())   return;
    
    // 치킨집 선택
    selected[idx] =true;
    dfs(idx+1, select+1);
    
    // 치킨집 선택 X
    selected[idx] =false;
    dfs(idx+1, select);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            
            if(map[i][j]==1) home.push_back(make_pair(i,j));
            if(map[i][j]==2) chicken.push_back(make_pair(i,j));
        }
    }
    
    dfs(0,0);
    
    cout<< min_dist <<endl;
  
    return 0;
}
