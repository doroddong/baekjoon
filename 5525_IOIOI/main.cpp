//
//  main.cpp
//  5525_IOIOI
//
//  Created by 이동훈 on 2020/11/03.
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

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> m;
    string s;
    cin >> s;
    
    string pn ="I";
    
    for(int i=0;i<n;i++){
        pn.push_back('O');
        pn.push_back('I');
    }
    int idx = 0;
    int cnt=0;
    
    for(int i=0;i<s.size()-pn.size();i++){
        
    }
    
    return 0;
}

