//
//  main.cpp
//  N과M시리즈
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
vector<int> arr;        // 초기 n 배열
int ans[8];             // 정답 배열
vector<bool> visited;   //사용한 것인지 검사 (중복 사용 검사에 사용)

void dfs(int num, int cnt)
{
    if(cnt==m){
        for(int i=0;i<m;i++)    cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    
    /* *************************************************
     
     prev_num에 직전에 골랐던 수를 저장
     전역변수로 선언하지 않는 이유 :
        1. 지역 변수로 선언하여 계속 초기화가 되도록 유도
            -> 맨 처음에 고르는 수는 직전에 골랐던 수와 관계없이 고르기 위함
        2. 함수의 재귀 호출이 끝나면 for문 안에서 다음 수를 고르는데
            그 때 prev_num에 저장된 수를 고르지 않기 위함
     
     *************************************************** */
    
    
    int prev_num = -1;
    
    for(int i=num;i<n;i++){
        if(prev_num != arr[i]){      // 이미 고른 수가 아니고 직전에 골랐던 수가 아니면
            ans[cnt] = arr[i];
            prev_num = arr[i];                      // 직전에 고른 수에 저장
            dfs(i,cnt+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    arr.resize(n);
    visited.resize(n,false);
    
    for(int i=0;i<n;i++)    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    
    dfs(0,0);
    
    return 0;
}
