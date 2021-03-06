//
//  main.cpp
//  11437_LCA
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

int depth[MAX_NODE];
int ac[MAX_NODE][20];
vector<int> graph[MAX_NODE];

int max_level;
int n,m;

void getTree(int here, int parent){
  depth[here] = depth[parent]+1;
  ac[here][0] = parent;
  max_level = (int) floor(log2(MAX_NODE));

  for(int i=1;i<=max_level;i++){
    int tmp = ac[here][i-1];
    ac[here][i]= ac[tmp][i-1];
  }

  int len = graph[here].size();
  for(int i=0;i<len;i++){
    int there = graph[here][i];
    if(there!=parent){
      getTree(there,here);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i=1;i<n;i++){
    int from,to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  depth[0]=-1;
  getTree(1,0);

  cin >> m;

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;

    if(depth[a]!=depth[b]){
      if(depth[a]>depth[b]){
        swap(a,b);
      }
      for(int i=max_level;i>=0;i--){
        if(depth[a]<=depth[ac[b][i]]){
          b = ac[b][i];
        }
      }
    }
    int lca =a;

    if(a!=b){
      for(int i=max_level;i>=0;i--){
        if(ac[a][i] != ac[b][i]){
          a= ac[a][i];
          b= ac[b][i];
        }
        lca = ac[a][i];
      }
    }
    cout<< lca <<endl;
  }
  return 0;
}
