//
//  main.cpp
//  10773_제로
//
//  Created by 이동훈 on 2020/11/12.
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
#include <stack>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> k;
    
    stack<int> s;
    
    for(int i=0;i<k;i++){
        int cur;
        cin >> cur;
        
        if(cur==0){
            s.pop();
        }
        else{
            s.push(cur);
        }
    }
    long long sum =0;
    
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        
        sum += cur;
    }
    cout<< sum << endl;

    return 0;
}

