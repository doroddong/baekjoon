//
//  main.cpp
//  1197_최소스패닝트리
//
//  Created by 이동훈 on 2021/10/09.
//  Copyright © 2021 이동훈. All rights reserved.
//
// 사용 알고리즘 : 크루스칼 알고리즘, Union-Find


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

int v,e_cnt; // 정점 개수, 간선 개수
vector<pair<int, pii>> edges;   // <출발 정점, <도착 정점, Cost>>
vector<int> parent(MAX,0);      // 부모 개수

// 간선의 비용 오름차순으로 정렬하기 위한 함수
bool cmp (pair<int, pii> a, pair<int, pii> b){
    return a.second.second < b.second.second;
}

int find(int v){
    if(v == parent[v]) return v;
    else return parent[v] = find(parent[v]);
}

void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(a==b) return ;
    else parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> v >> e_cnt;
    
    for(int i=0;i<v;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<e_cnt;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        
        edges.push_back(make_pair(from, make_pair(to, cost)));
    }
    
//    for(int i=0;i<e_cnt;i++){
//        cout << edges[i].first << edges[i].second.first << edges[i].second.second << endl;
//    }
    
    sort(edges.begin(), edges.end(), cmp);
    
//    for(int i=0;i<e_cnt;i++){
//        cout << edges[i].first << edges[i].second.first << edges[i].second.second << endl;
//    }
    
    ll ret = 0;
    for(auto now : edges){
        if(find(now.first) != find(now.second.first)){
            ret += now.second.second;
            unite(now.first, now.second.first);
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
