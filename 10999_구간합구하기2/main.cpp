//
//  main.cpp
//  10999_구간합구하기2
//
//  Created by 이동훈 on 2020/09/27.
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

int n,m,k;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
    if(start == end) return tree[node] = a[start];
    
    else{
        return tree[node] = init(a,tree,2*node, start, (start+end)/2)
                                + init(a, tree, 2*node +1, (start + end)/2 +1, end);
    }
}

void update_lazy(vector<long long> &tree,vector<long long> &lazy, int node, int start, int end)
{
    // lazy값이 있으면 노드의 수 (end - start + 1)만큼 곱해서 더해줌
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        
        // leaf 가 아니면 , 좌우 노드에 lazy 값 전달하고 현재 노드의 lazy 값은 0으로 초기화
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2 +1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
    
// 범위만큼 update
void update_range(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right, long long diff)
{
    update_lazy(tree, lazy, node, start, end);
    
    // 아예 범위에 안 속해있다면 return
    if(left > end || right < start) return;

    // 범위에 속해있다면 갱신하고 리프 노드가 아니라면 lazy값을 자식들에게 넘겨주고 종료
    if(left <= start && end <= right){
        tree[node] += (end-start+1) * diff;
        if(start != end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    
    // 더 깊숙히 가야한다면 ( 범위가 애매하게 걸침) -> 더 탐색하고 tree값을 갱신
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2 +1, (start+end)/2+1,end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right){
    update_lazy(tree,lazy,node, start, end);

    // 범위에 안 속해 있다면 종료
    if(left > end || right < start) return 0;

    // 범위에 정확하다면 tree값 반환
    if(left <= start && end <= right) return tree[node];

    // 범위가 애매하다면 더 탐색해보자.
    return sum(tree,lazy, node*2, start, (start+end)/2, left, right) + sum(tree, lazy, node*2+1, (start+end)/2 +1, end, left, right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    
    
    vector<long long> arr(n);
    vector<long long> tree(4*n);
    vector<long long> lazy(4*n);
    
    for(int i=0;i<n;i++) cin >> arr[i];
    
    init(arr, tree,1,0,n-1);
    
    for(int i=0; i< m+k;i++){
        int a,b,c,d;
        cin >> a;
        
        if(a==1){
            cin >> b >> c >> d;
            update_range(tree,lazy,1,0,n-1,b-1,c-1,d);
        }
        
        else{
            cin >> b >> c;
            cout << sum(tree,lazy,1,0,n-1,b-1,c-1)<<endl;
        }
    }
  
    return 0;
}
