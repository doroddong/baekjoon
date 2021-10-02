//
//  main.cpp
//  2156_포도주시식
//
//  Created by 이동훈 on 2020/09/27.
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
#define MAX 10001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int arr[MAX], dp[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        
    }
    
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    
    for(int i=3;i<=n;i++){
        // dp[i] :  1. i잔은 마시고, i-1잔은 마시지 않은 경우 -> dp[i-2] + arr[i]
        //          2. i잔은 마시고, i-1잔도 마신 경우  -> i-2까지 마시면 안됨 -> dp[n-3] + arr[i-1] + arr[i]
        //          3. 연속 두 번 안 마신 경우 -> dp[i-1] 을 그대로 받는다.
        dp[i] = max(max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]),dp[i-1]);
    }
    
    cout << dp[n] <<endl;
  
    return 0;
}
