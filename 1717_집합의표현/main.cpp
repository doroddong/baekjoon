//
//  main.cpp
//  1717_집합의표현
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
#define MAX 1000001
#define INF 987654321
#define endl "\n"

using namespace std;

int n, m;
int root[MAX];

int find(int x){
    if(root[x] == x)    return x;
    
    return root[x] = find(root[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if( x != y){
        root[y] = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<=n;i++){
        root[i] = i;
    }
    
    for(int i=0;i<m;i++){
        int oper, a, b;
        cin >> oper >> a >> b;
        
        if(oper == 0)   unite(a,b);
        
        if(oper == 1){
            int x = find(a);
            int y = find(b);
            
            if(x==y)    cout<<"YES"<<endl;
            else    cout<<"NO"<<endl;
            
        }
    }
  
    return 0;
}
