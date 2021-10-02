//
//  main.cpp
//  10775_공항
//
//  Created by 이동훈 on 2020/09/01.
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

int g, p, cnt =0;
int root[MAX], depth[MAX];
vector<int> v;

int find(int x){
    if(root[x] == x) return x;
    
    return root[x] = find(root[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    root[x] =y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> g >> p;
    
    for(int i=1; i<=g;i++)  root[i] = i;
    
    for(int i=0;i<p;i++){
        int gi;
        cin >> gi;
        
        // gi의 root를 찾음
        int dock = find(gi);
        
        // root가 0이 아니라면 (도킹할 자리가 남았다면) -> 개수 추가, dock의 root 를 dock-1로 unite(트리화)
        if(dock!= 0){
            cnt++;
            unite(dock, dock-1);
        }
        // 도킹할 자리가 없다면 -> break
        else{
            break;
        }
    }
    cout<< cnt <<endl;
    
    return 0;
}
