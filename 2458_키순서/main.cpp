//
//  main.cpp
//  2458_키순서
//
//  Created by 이동훈 on 2020/09/25.
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

int n,m;
vector<int> bigger[501],smaller[501];

int bigger_dfs(int cur){
    int cnt =0;
    if(bigger[cur].size()==0){
        return 1;
    }
    
    for(int i=0;i<bigger[cur].size();i++){
        cnt+= bigger_dfs(bigger[cur][i]);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int big, small;
        cin >> small >> big;
        
        bigger[small].push_back(big);
        smaller[big].push_back(small);
    }
    
    for(int i=1;i<=n;i++){
        dfs(i);
    }
  
    return 0;
}
