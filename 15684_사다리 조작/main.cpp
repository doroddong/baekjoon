//
//  main.cpp
//  15684_사다리 조작
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
#define INF 987654321
#define endl "\n"

int n,m,h,ans=999;
int map[30][11];
bool visited[30][11];

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// 사다리가 각각 자기 자신으로 돌아오는지 확인
bool is_possible(){
    for(int i=1;i<=n;i++){
        int cur_num =i;             // 인덱스 임시 저장
        for(int j=1;j<=h;j++){
            // 오른쪽으로 가는 선이라면, 오른쪽 인덱스로 이동
            if(visited[j][cur_num]) cur_num ++;
            // 왼쪽으로 가는 선이라면, 왼쪽 인덱스로 이동
            else if(visited[j][cur_num-1]) cur_num--;
        }
        // 자기 자신이 아니라면 false 리턴
        if(cur_num != i) return false;
    }
    // 참 리턴
    return true;
}

void dfs(int idx,int cnt){
    if(cnt>3) return;       // 카운트가 3이상이라면 리턴
    if(cnt>=ans) return;
    
    if(is_possible()){      // 가능한 사다리 조작이면 최소값 계산
        ans = min(ans,cnt);
        return;
    }
    
    for(int i= idx; i<=h;i++){
        for(int j=1;j<n;j++){
            // 가로선을 추가할 수 없는 위치라면 continue
            if(visited[i][j]) continue;
            if(visited[i][j-1]) continue;
            if(visited[i][j+1]) continue;
            
            // 선 추가하고 dfs 수행
            visited[i][j] = true;
            dfs(i,cnt+1);
            visited[i][j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> h;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        visited[a][b] = true;
    }
    
    dfs(1,0);
    
    if(ans==999)  ans=-1;
    cout<<ans<<endl;
  
    return 0;
}
