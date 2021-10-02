//
//  main.cpp
//  2252_줄세우기
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
int in_degree[MAX];     //진입차수를 저장하는 배열
vector<int> graph[MAX]; // 단방향의 그래프

void topology_sort(){
    int result[n];      // 결과를 담는 배열
    queue<int> q;
    
    // 시작점 (진입차수가 0인 node)를 큐에 푸시
    for(int i=1;i<=n;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    
    // n이 될 때까지 돌아야한다.
    for(int i=1;i<=n;i++){
        // n까지 안 돌았을 떄 큐가 비어있으면 위상정렬 불가능
        if(q.empty())   return;
        
        // front를 꺼내서 i번쨰에 저장
        int x = q.front();
        q.pop();
        result[i] = x;
        
        // front와 연결된 노드들을 큐에 저장하면서 진입차수 -1
        for(int j=0;j<graph[x].size();j++){
            int y = graph[x][j];
            
            if(--in_degree[y]==0){
                q.push(y);
            }
        }
    }
    
    // 결과 출력
    for(int i=1;i<=n;i++){
        cout << result[i] << " ";
    }
    cout <<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        // indegree를 증가
        in_degree[to]++;
    }
    
    topology_sort();
  
    return 0;
}

