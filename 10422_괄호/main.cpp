//
//  main.cpp
//  10422_괄호
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
#define MAX 5001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t;
ll dp[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    dp[0] = 1;
    dp[2] = 1;
    for(int i=3;i<5001;i++){
        
        // () (....) -> 두개로 만들수 있는것 * 두개뺀걸로 만들 수 있는 것
        // (()) (...) -> 4개로 만들 수 있는것 * 4개 뺀걸로 만들 수 있는 것
        //. ....          이렇게 나머지도 모두 곱해서 더해준 후 1e9+7로 나눠줌
        
        for(int j=2;j<=i;j++){
            dp[i] += dp[j-2] * dp[i-j];
            dp[i] %= (ll)1e9+7;
        }
    }
    
    for(int i= 0 ;i<t;i++){
        int l;
        cin >> l;
        cout<<dp[l]<<endl;
    }
  
    return 0;
}
