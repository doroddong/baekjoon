//
//  main.cpp
//  1368_물대기
//
//  Created by 이동훈 on 2020/09/08.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define INRANGE(R,C,r,c) ((r>=0)&&(c>=0)&&(r<R)&&(c<C))
#define INF 987654321
#define LLMAX (1LL << 50)
#define MAXNODE 101
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;

int cost[301][301];
int connected[301];

int main() {
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> q;
    int n, c, conn = 0, ans = 0; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cost[i][i];
        q.push({cost[i][i],{i,i}});
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            if(i != j) cost[i][j] = c;
        }
    }
    
    while(conn < n){
        pair<int,pii> edge = q.top(); q.pop();
        int _cost = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;
        
        if(from == to && !connected[from]){
            connected[from] = 1;
            ans += _cost;
            ++conn;
            for(int i = 0; i < n; i++){
                if(!connected[i]){
                    q.push({cost[from][i], {from, i}});
                }
            }
        }
        else if(!connected[to]){
            connected[to] = 1;
            ans += _cost;
            ++conn;
            for(int i = 0; i < n; i++){
                if(!connected[i]){
                    q.push({cost[to][i], {to, i}});
                }
            }
        }
        
    }
    
    cout << ans << endl;
    
}
