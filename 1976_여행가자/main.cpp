//
//  main.cpp
//  1976_여행가자
//
//  Created by 이동훈 on 2020/08/31.
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
#define MAX 201
#define INF 987654321
#define endl "\n"

using namespace std;

int n,m;
int edges[MAX][MAX];
int root[MAX];
int depth[MAX];

// x의 root를 찾음
int find(int x){
    if(x == root[x])    return x;
    // 경로 압축
    else return root[x] = find(root[x]);
}

// x, y 를 이어줌
void Union(int x, int y){
    x = find(x);
    y = find(y);
    
    // 이어져 있다면 return
    if(x == y) return;
    
    // depth가 다르다면 이어줌 (단, 작은 트리가 큰 트리에 붙음)
    if(depth[x] < depth[y])  root[x] = y;
    else    root[y] = x;
    
    // depth가 같다면 +1
    if(depth[x] == depth[y])  depth[x]++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    // 초기화
    for(int i=1;i<=n;i++){
        root[i]= i;
        depth[i]=0;
    }
    
    // 연결되어있다면 Union 수행
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> edges[i][j];
            if(edges[i][j]==1){
                Union(i,j);
            }
        }
    }
    
    // 이어져있다면 pass
    // 이어져있지 않다면 break
    int from;
    cin >> from;
    bool flag=true;
    for(int i=0;i<m-1;i++){
        int to;
        cin >> to;
        // root 가 서로 다르면 (이어져있지 않음)
        if(find(from) != find(to)){
            flag = false;
            break;
        }
        from = to;
    }
    
    // flag가 true (모두 이어져있음)
    if(flag) cout<<"YES"<<endl;
    // 이어져 있지 않음
    else cout<<"NO"<<endl;
    
  
    return 0;
}
