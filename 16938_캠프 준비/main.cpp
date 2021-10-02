//
//  main.cpp
//  16938_캠프 준비
//
//  Created by 이동훈 on 2020/10/01.
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

int a[15];
int n,l,r,x;
int ans=0;

void dfs(int idx,int cnt, int sum , int high,int low){
    // 2문제 이상 선택
    if(cnt>=2){
        // 조건에 맞으면 +1
        if(sum >= l && sum<=r && high-low >=x)
        {
            ans++;
        }
        
        // idx가 끝까지 탐색헀다면 종료
        if(idx==n)  return;
    }
    
    // 다음 조합 선택
    for(int i = idx;i<n;i++){
        dfs(i+1, cnt+1, sum+a[i], max(high,a[i]), min(low,a[i]));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> l >> r >> x;
    
    for(int i=0;i<n;i++)    cin >> a[i];
    
    dfs(0,0,0,0,INF);
    
    cout << ans <<endl;
    
    return 0;
}
