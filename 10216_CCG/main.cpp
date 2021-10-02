//
//  main.cpp
//  10216_CCG
//
//  Created by 이동훈 on 2020/09/03.
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
#define MAX 5001
#define INF 987654321
#define endl "\n"

using namespace std;

int bloc[MAX][3];
int parent[MAX];

int t,n;

int find(int x){
    if(x == parent[x])  return x;
    else return parent[x] = find(parent[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    else    parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        
        for(int i=0;i<n;i++){
            cin >> bloc[i][0] >> bloc[i][1] >> bloc[i][2];
            parent[i] = i;
        }
        int cnt = n;
        
        for(int i=0;i<n;i++){
            for(int j= i+1 ; j<n;j++){
                int dis_x = bloc[i][0] - bloc[j][0];
                int dis_y = bloc[i][1] - bloc[j][1];
                int r = bloc[i][2] + bloc[j][2];
                int d = dis_x * dis_x + dis_y * dis_y;
                
                if(d <= r*r){
                    if(find(i)!= find(j)){
                        unite(i,j);
                        cnt--;
                    }
                }
            }
        }
        cout<<cnt<<endl;
        
    }
    
  
    return 0;
}
