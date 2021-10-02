//
//  main.cpp
//  1966_프린터 큐
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
//#include <priority_queue>

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
    
    int t;
    
    cin >> t;
    vector<int> v;
    
    for(int i=0;i<t;i++){
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        int n, m;
        cin >> n >> m;
        
        for(int j=0;j<n;j++){
            int importance;
            cin >> importance;
            
            q.push(make_pair(j, importance));
            pq.push(importance);
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            int cur_docs = q.front().first;
            int cur_importance = q.front().second;
            q.pop();
            
            if(pq.top() == cur_importance){
                pq.pop();
                cnt++;
                if(cur_docs == m){
                    cout << cnt << endl;
                    break;
                }
            }
            else q.push(make_pair(cur_docs, cur_importance));
        }
    }
    
    
    return 0;
}

