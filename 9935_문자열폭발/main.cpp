//
//  main.cpp
//  9935_문자열폭발
//
//  Created by 이동훈 on 2020/09/25.
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

int loc =0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string origin, boom;
    
    cin >> origin >> boom;
    
    int bs = boom.size();

    while(1){
        int idx = (int)origin.find(boom,loc);
        cout<<loc<<" "<<idx<<endl;
        
        
        if(idx !=-1){
            origin = origin.substr(0,idx) + origin.substr(idx+bs);
            
            loc = idx - bs;
            if(loc<0){
                loc = 0;
            }
        }
        else{
            break;
        }
    }
    
    if(origin ==""){
        cout<<"FRULA"<<endl;
    }
    else{
        cout<< origin <<endl;
    }

  
    return 0;
}
