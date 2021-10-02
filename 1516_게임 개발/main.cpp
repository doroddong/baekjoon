//
//  main.cpp
//  1516_게임 개발
//
//  Created by 이동훈 on 2020/09/18.
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
#define INF 987654
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int arr[501], num[501];
int dp[501];
vector<int> graph[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
        
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        arr[i]=t;
        
        while(1){
            int con;
            cin >> con;
            
            if(con ==-1)    break;
            else {
                num[i]++;
                graph[con].push_back(i);
            }
        }
    }
    
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(num[i]==0){
            q.push(i);
            dp[i] = arr[i];
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            num[next]--;
            
            dp[next] = max(dp[next], dp[cur] + arr[next]);
            if(num[next]==0)   q.push(next);
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<< dp[i] <<endl;
    }
  
    return 0;
}
