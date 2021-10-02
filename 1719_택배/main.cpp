//
//  main.cpp
//  1719_택배
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

#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX_NODE 100001
#define INF 987654321

using namespace std;

int n,m;
int adj[201][201];    // 거리를 담는 공간
int start[201][201];  // 시작하는 지점을 담는 공간

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;

  // 초기화
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      adj[i][j] = INF;
    }
  }

  // 입력 및 초기화
  for(int i=0;i<m;i++){
    int from , to , dis;
    cin >> from >> to >> dis;
    adj[from][to] = dis;
    adj[to][from] = dis;
    start[from][to]=to;
    start[to][from]=from;
  }

  // 플로이드-와샬 알고리즘 수행
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(adj[i][j]> adj[i][k]+adj[k][j]){   // 경유지가 더 빠르다면
          adj[i][j]= adj[i][k] + adj[k][j];
          start[i][j]=start[i][k];            // 시작점을 바꿔줌
        }
      }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) cout<< "- ";
      else  cout << start[i][j] << " ";
    }
    cout<<endl;
  }
  
  return 0;
}
