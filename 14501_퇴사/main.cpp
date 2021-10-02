//
//  main.cpp
//  14501_퇴사
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
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[17];
int t[17];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> t[i] >> p[i];
    }
    
    int ans =0;
    for(int i=n;i>=1;i--){
        if(i+t[i]>n+1){
            p[i] = p[i+1];
        }
        else{
            p[i]  = max(p[i+1],p[i]+p[i+t[i]]);
        }
        ans = max(ans,p[i]);
    }
    cout<< ans << endl;
  
    return 0;
}
