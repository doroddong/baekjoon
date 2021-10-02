//
//  main.cpp
//  9372_상근이의여행
//
//  Created by 이동훈 on 2020/11/07.
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

int t, n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    
    while(t--){
        cin >> n >> k;
        vector<int> graph[n+1];
        
        for(int i=0;i<k;i++){
            int from, to;
            cin >> from >> to;
            
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
    }
    
    return 0;
}

