//
//  main.cpp
//  1027_고층건물
//
//  Created by 이동훈 on 2020/09/06.
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
#include <climits>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 51
#define INF 987654321
#define endl "\n"

using namespace std;

int n;
int building[MAX],cnt[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> building[i];
    }
    
    for(int i=0;i<n;i++){
        double angle = -99999999999;
        
        for(int j=i+1;j<n;j++){
            double cur = double(building[j]-building[i])/(j-i);
            if(angle < cur) {
                angle = cur;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    int ans = -1;
    for(int i=0;i<n;i++){
        if(ans < cnt[i])    ans = cnt[i];
    }
    
    cout<< ans<<endl;
    
  
    return 0;
}
