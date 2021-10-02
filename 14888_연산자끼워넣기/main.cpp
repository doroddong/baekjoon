//
//  main.cpp
//  14888_연산자끼워넣기
//
//  Created by 이동훈 on 2020/08/28.
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
#define MAX 12
#define INF 1000000001
#define endl "\n"

using namespace std;

int n;
int oper[4];
int arr[MAX];
int max_result = -INF;
int min_result = INF;

void dfs(int plus_num, int minus_num, int multiply_num, int divide_num, int cnt,int sum){
    if(cnt == n){
        max_result = max(max_result,sum);
        min_result = min(min_result,sum);
    }
    
    if(plus_num>0)  dfs(plus_num-1, minus_num, multiply_num, divide_num, cnt+1, sum + arr[cnt]);
    if(minus_num>0) dfs(plus_num, minus_num-1, multiply_num, divide_num, cnt+1 , sum - arr[cnt]);
    if(multiply_num>0) dfs(plus_num, minus_num, multiply_num-1, divide_num, cnt+1, sum * arr[cnt]);
    if(divide_num>0) dfs(plus_num, minus_num, multiply_num, divide_num-1, cnt+1, sum / arr[cnt]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<4;i++){
        cin >> oper[i];
    }
    
    dfs(oper[0],oper[1],oper[2],oper[3],1,arr[0]);
    
    cout << max_result <<endl;
    cout << min_result <<endl;
  
    return 0;
}
