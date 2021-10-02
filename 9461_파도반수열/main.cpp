//
//  main.cpp
//  9461_파도반수열
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
#define MAX 101
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t;

ll dp[MAX]= {1,1,1,1,2,2,3,};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=7;i<=MAX;i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        cout<< dp[n] <<endl;
    }
  
    return 0;
}
