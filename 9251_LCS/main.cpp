//
//  main.cpp
//  9251_LCS
//
//  Created by 이동훈 on 2020/09/10.
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
#define MAX 1001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string x,y;
    
    cin >> x >> y;
    
    // 이차원 배열로 dp 배열 생성
    for(int i=1;i<=x.length();i++){
        for(int j=1;j<=y.length();j++){
            //비교하는 문자열이 같을 경우
            if(x[i-1]==y[j-1]){
                // 현재의 좌대각에 길이를 +1
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            // 다른 경우, 위나 왼쪽에서 최대인 것 고름
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<< dp[x.length()][y.length()]<<endl;
    
    return 0;
}
