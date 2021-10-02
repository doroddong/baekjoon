//
//  main.cpp
//  2665_미로만들기
//
//  Created by 이동훈 on 2020/08/24.
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
#define MAX_NODE 100001
#define INF 987654321

using namespace std;

int dir_x[4] ={0,0,-1,1};
int dir_y[4] = {-1,1,0,0};

int n;
int room[51][51];
int visited[51][51];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<s.length();j++){
      room[i][j]= s[j]-'0';
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;i<n;j++){
      visited[i][j]=INF;
    }
  }

  queue<pair<int,int>> q;
  visited[0][0]=0;
  q.push(make_pair(0,0));
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i=0;i<4;i++){
      int next_x = x + dir_x[i];
      int next_y = y + dir_y[i];

      if(inRange(next_x,next_y,n,n)==1){
        if(room[next_x][next_y]==1){
          if(visited[next_x][next_y] > visited[x][y]){
            visited[next_x][next_y]= visited[x][y];
            q.push(make_pair(next_x,next_y));
          }
        }
        else{
          if(visited[next_x][next_y] > visited[x][y]+1){
            visited[next_x][next_y] = visited[x][y]+1;
            q.push(make_pair(next_x,next_y));
          }
        }
      }
    }
  }
  cout<<visited[n-1][n-1]<<endl;
  return 0;
}
