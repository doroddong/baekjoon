//
//  main.cpp
//  1316_그룹단어체커
//
//  Created by 이동훈 on 2020/11/03.
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

int n;
bool alpha[26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    int cnt=n;
    
    for(int i=0;i<n;i++){
        memset(alpha,false,sizeof(alpha));
        string s;
        cin >> s;
        
        char prev='A';
        char cur;
        for(int j=0;j<s.size();j++){
            cur = s[j];
            
            if(cur==prev) continue;
            else if(alpha[cur-'a']){
                cnt--;
                break;
            }
            else{
                alpha[cur-'a'] = true;
                prev = cur;
            }
        }

    }
    cout<<cnt<<endl;
    
    return 0;
}

