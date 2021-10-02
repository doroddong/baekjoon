//
//  main.cpp
//  9012_괄호
//
//  Created by 이동훈 on 2020/11/02.
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        stack<char> sta;
        string s;
        cin >> s;
        
        for(int j=0;j<s.size();j++){
            if(sta.empty() || s[j]=='(') sta.push(s[j]);
            else if(sta.top()=='(') sta.pop();
        }
        
        if(sta.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}

