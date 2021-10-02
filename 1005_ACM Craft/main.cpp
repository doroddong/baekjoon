//
//  main.cpp
//  1005_ACM Craft
//
//  Created by 이동훈 on 2020/10/04.
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
#define MAX 1001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t, n, k;
vector<int> graph[MAX];
int in_degree[MAX];
int result[MAX];
int cost[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    while(t--){
        // 초기화 (꼭 해야함)
        memset(in_degree,0,sizeof(in_degree));
        memset(result,0, sizeof(result));
        memset(cost,0,sizeof(cost));
        for(int i=0;i<MAX;i++) graph[i].clear();
        
        cin >> n >> k;
        
        for(int i=1;i<=n;i++){
            cin >> cost[i];
        }
        
        for(int i=0;i<k;i++){
            int from, to;
            cin >> from >> to;
            
            graph[from].push_back(to);
            in_degree[to]++;
        }
        int w;
        cin >> w;
        
        queue<int> q;
        
        // 초기 상태 설정
        // 시작점이라면 큐에 푸시하고 result 값 갱신
        for(int i=1;i<=n;i++){
            if(in_degree[i]==0){
                q.push(i);
                result[i] = cost[i];
            }
        }
        
        // 문제에서 위상 정렬이 안 될 가능성을 명시해주지 않았기 때문에 두 가지 방법으로 가능
        while(!q.empty()){
//        for(int i=1;i<=n;i++){
            int cur = q.front();
            q.pop();
            
            // 더 큰 시간이 소요된다면 갱신
            for(int j=0;j<graph[cur].size();j++){
                int next = graph[cur][j];
                
                result[next] = max(result[next],result[cur]+cost[next]);
                // 진입차수가 0이라면 큐에 푸시
                if(--in_degree[next]==0){
                    q.push(next);
                }
            }
        }
        cout<< result[w] <<endl;
    }
  
    return 0;
}

