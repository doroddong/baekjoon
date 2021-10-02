//
//  main.cpp
//  2143_두배열의합
//
//  Created by 이동훈 on 2020/09/24.
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
ll t;

int a[1000], b[1000];
vector<int> a_part_sum, b_part_sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    cin >> m;
    
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    
    for(int i=0;i<n;i++){
        int sum = a[i];
        a_part_sum.push_back(sum);
        for(int j=i+1;j<n;j++){
            sum += a[j];
            a_part_sum.push_back(sum);
        }
    }
    
    for(int i=0;i<m;i++){
        int sum = b[i];
        b_part_sum.push_back(sum);
        for(int j=i+1;j<m;j++){
            sum += b[j];
            b_part_sum.push_back(sum);
        }
    }
    
    sort(b_part_sum.begin(),b_part_sum.end());
    
    ll ans=0;
    
    for(auto item : a_part_sum){
        ll diff = (t - item);
        auto ub = upper_bound(b_part_sum.begin(), b_part_sum.end(), diff);
        auto lb = lower_bound(b_part_sum.begin(), b_part_sum.end(), diff);
        ans += ub - lb;
    }
    
    cout<< ans <<endl;
  
    return 0;
}
