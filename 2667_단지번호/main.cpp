//
//  main.cpp
//  2667_단지번호
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

int n, cnt;
int check[25][25];
int map[25][25];
vector<int> home_num;

int dx[4] = {-1,0,1,0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x,int y){
    
    int cnt =1;
    check[x][y] =true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for(int i =0 ; i<4 ; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y+ dy[i];
            
            if(next_x <0 || next_x >= n || next_y<0 || next_y>=n)   continue;
            
            if(!check[next_x][next_y] && map[next_x][next_y]){
                check[next_x][next_y] = true;
                
                cnt++;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
    home_num.push_back(cnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        
        for(int j=0;j<s.size();j++){
            map[i][j] = s[j]-'0';
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(!check[i][j] && map[i][j]){
                bfs(i,j);
            }
        }
    }
    
    sort(home_num.begin(),home_num.end());
    
    
    cout<<home_num.size()<<endl;
    for(int i=0; i<home_num.size();i++){
        cout << home_num[i] <<endl;
    }
    
    
    

  
    return 0;
}
