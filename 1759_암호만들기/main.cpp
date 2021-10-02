//
//  main.cpp
//  1759_암호만들기
//
//  Created by 이동훈 on 2020/09/30.
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

int l, c;
char alpha[15];

void dfs(int idx, int cnt, int mo, int ja, string cur){
    if(cnt==l){
        if(mo>=1 && ja >=2){
            cout<<cur<<endl;
            return;
        }
    }
    if(idx == c) return;
    
    if(alpha[idx]=='a' || alpha[idx]=='e' || alpha[idx]=='i' || alpha[idx]=='o' || alpha[idx]=='u' ){
        dfs(idx+1, cnt+1, mo+1, ja, cur+alpha[idx]);
    }
    else {
        dfs(idx+1, cnt+1, mo, ja+1, cur+alpha[idx]);
    }
    
    dfs(idx+1, cnt,mo,ja,cur);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> l >> c;
    
    for(int i=0;i<c;i++){
        cin >> alpha[i];
    }
    
    sort(alpha,alpha+c);
    
    dfs(0,0,0,0,"");

  
    return 0;
}
