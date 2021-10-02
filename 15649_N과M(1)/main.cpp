//
//  main.cpp
//  15649_N과M(1)
//
//  Created by 이동훈 on 2020/09/17.
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

int n, m;
int arr[8];
int visited[10];

void dfs(int cnt){
    if(cnt==m){
        for(int i=0;i<m;i++)    cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[cnt] = i;
            dfs(cnt+1);
            visited[i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    dfs(1,0);
    
    return 0;
}
