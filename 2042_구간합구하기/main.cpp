//
//  main.cpp
//  2042_구간합구하기
//
//  Created by 이동훈 on 2020/09/22.
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
#define MAX 1000001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll arr[MAX];
ll tree[4*MAX];

int n,m,k;

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) /2;
    return tree[node] = init(start,mid, node*2) + init(mid+1, end,node*2+1);
}

ll sum (int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) /2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1,left,right);
}

void update(int start, int end, int node, int index, ll diff){
    if(index<start || index> end) return;
    
    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) /2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2 + 1, index, diff);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init(1,n,1);
    
    for(int i=0;i<m+k;i++){
        int a,b,c,d;
        cin >> a;
        
        if(a==1){
            cin >> b >> c >> d;
            for(int i=b;i<=c;i++){
                update(1,n,1,i,d);
            }
        }
        else{
            cin >> b >> c;
            cout<<sum(1,n,1,b,c)<<endl;
        }
    }
    
    
  
    return 0;
}
