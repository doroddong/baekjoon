//
//  main.cpp
//  5555_반지
//
//  Created by 이동훈 on 2020/11/05.
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int n;
    cin >> n;
    
    int cnt=0;
    for(int i=0;i<n;i++){
        string ring;
        cin >> ring;
        ring+=ring;
        
        if(ring.find(s) != string::npos){
            cnt++;
        }
    }
    
    cout<< cnt << endl;
    

    return 0;
}

