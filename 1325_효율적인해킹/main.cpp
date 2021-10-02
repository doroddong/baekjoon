//
//  main.cpp
//  1325_효율적인해킹
//
//  Created by 이동훈 on 2020/10/28.
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
vector<int> graph[MAX];
vector<int> answer;
bool visit[MAX];
int cnt;
void dfs(int node){
    visit[node] = true;
    
    for(int i=0;i<graph[node].size();i++){
        int next = graph[node][i];
        
        if(!visit[next]){
            cnt++;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    
    int node_cnt=0;
    for(int i=1;i<=n;i++){
        memset(visit,false,sizeof(visit));
        cnt =0;
        
        dfs(i);
        if(node_cnt==cnt){
            answer.push_back(i);
        }
        else if(node_cnt<cnt){
            node_cnt = cnt;
            answer.clear();
            answer.push_back(i);
        }
    }
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}

