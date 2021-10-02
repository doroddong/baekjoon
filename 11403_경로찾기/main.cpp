//
//  main.cpp
//  11403_경로찾기
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

using namespace std;

int n;
int adj[101][101];
int ans[101][101];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> adj[i][j];
    }
  }

  // 플로이드-와샬 알고리즘 응용
  for(int k=0;k<n;k++){         // 경유 정점
    for(int i=0;i<n;i++){       // 시작 정점
      for(int j=0;j<n;j++){     // 끝 정점
        if(adj[i][j] || (adj[i][k] && adj[k][j])) ans[i][j]=1;    //직접 경로가 있는지
        if(ans[i][j] || (ans[i][k] && ans[k][j])) adj[i][j]=1;    //간접 경로가 있는지
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << ans[i][j]<<" ";
    }
    cout<<endl;
  }
  
  return 0;
}
