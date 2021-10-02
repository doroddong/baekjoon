//
//  main.cpp
//  2098_외판원 순회
//
//  Created by 이동훈 on 2020/10/02.
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
#define MAX 16
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int map[MAX][MAX];
int cost[MAX][1<<MAX];

int dfs(int cur_node, int cur_bit)
{
    // 현재 상태가 모두 한번씩 지났는데, (마지막 길만 남았다)
    if(cur_bit == (1 << n)-1){
        // 현재노드에서 마지막 0부터 가는길이 없다면, 길이 없으므로 INF 반환
        if(map[cur_node][0]==0) return INF;
        // 길이 있다면 map[cur_node][0]을 리턴
        else return map[cur_node][0];
    }
    
    // 해당 루트가 아예 처음이 아니라면, cost가 갱신되었을테니 cost 반환
    if(cost[cur_node][cur_bit] != -1)  return cost[cur_node][cur_bit];
    
    // 아예 처음이라면, INF 갱신
    cost[cur_node][cur_bit] = INF;

    // cur_node와 연결된 i로 기기
    for(int i=0;i<n;i++){
        if(map[cur_node][i]==0) continue;
        // cur_bit에 i로 이미 지나갔다면 무시
        if((cur_bit & (1<<i))) continue;
        
        // 최소값 갱신 (cost와 cur_node에서 i를 간 것과 그 다음 dfs 수행하여 최소인 거리)
        cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit], map[cur_node][i] + dfs(i,cur_bit | (1<<i) ));
    }
    return cost[cur_node][cur_bit];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    
    memset(cost, -1, sizeof(cost));
    cout<< dfs(0,1) << endl;
    
    return 0;
}
