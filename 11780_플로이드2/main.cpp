//
//  main.cpp
//  11780_플로이드2
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

#define endl '\n'
#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX_NODE 100001
#define INF  987654321

using namespace std;

int n,m;
int path[101][101];
int adj[101][101];
int cnt;

void route(int i, int j){
  if(path[i][j]!=0){
    route(i,path[i][j]);
    cout<< path[i][j]<<" ";
    route(path[i][j],j);
  }
}

void find_cost(int i,int j){
  if(path[i][j]!=0){
    cnt++;
    find_cost(i,path[i][j]);
    find_cost(path[i][j],j);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  // INF 로 초기화
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      adj[i][j] = INF;
    }
  }

  // 입력
  for(int i=0;i<m;i++){
    int from , to, dis;
    cin >> from >> to >> dis;
    adj[from][to]= min(adj[from][to],dis);
  }

  // 플로이드-와샬 알고리즘 - 경로가 갱신되면 path[i][j]에 k 저장
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i==j) continue;
        if(adj[i][j]>adj[i][k]+adj[k][j]){
          adj[i][j]= adj[i][k] + adj[k][j];
          path[i][j]=k;
        }
      }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) cout<<"0 ";
      else cout<< adj[i][j]<< " ";
    }
    cout<<endl;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) cout<<0<<endl;
      else{
        cnt=2;
        find_cost(i,j);
        cout << cnt << " " << i<<" ";
        route(i,j);
        cout<< j<< endl;
      }
    }
  }

  return 0;
}
