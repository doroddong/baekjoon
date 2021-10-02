//
//  main.cpp
//  11066_파일합치기
//
//  Created by 이동훈 on 2020/10/07.
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

bool desc(int a, int b){
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int k;
        cin >> k;
        
        int sum=0;
        vector<int> v;
        
        for(int i=0;i<k;i++){
            int c;
            cin >> c;
            v.push_back(c);
        }
        
        while(v.size()>1){
            sort(v.begin(), v.end(),desc);
            
            int less1 = v.back();
            v.pop_back();
            int less2 = v.back();
            v.pop_back();
            
//            cout<< less1 << " "<< less2 <<endl;
            
            int x = less1 + less2;
            sum += x;
            
            v.push_back(x);
            
        }
        
        cout<< sum << endl;
    }

    return 0;
}


