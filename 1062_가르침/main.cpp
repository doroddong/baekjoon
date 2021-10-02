//
//  main.cpp
//  1062_가르침
//
//  Created by 이동훈 on 2020/10/02.
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

int n,k,ans=0;
// 알파벳의 개수가 26
// 0은 'a', 25는 'z'를 담당하는 인덱스
bool alpha[26];
vector<string> words;


//
void dfs(int idx, int cnt){
    
    // 현재 개수가 k라면
    if(cnt == k){
        int possible =0;
        // 현재 배운 알파벳으로 해당 언어를 읽을 수 있는지 확인
        for(int i=0;i<n;i++){
            string s = words[i];
            bool flag = true;
            
            for(int j=0;j<s.size();j++){
                // alpha를 배우지 않은 거라면
                if(!alpha[s[j]-'a']){
                    flag = false;
                    break;
                }
            }
            // flag 가 true라면 가능한 단어
            if(flag) possible++;
        }
        // possible이 현재 ans보다 크다먄
        ans = max(ans, possible);
    }
    
    for(int i = idx ; i <26 ; i++){
        if(alpha[i]) continue;
        alpha[i] = true;
        dfs(i, cnt+1);
        alpha[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    for(int i=0; i<n;i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    
    // k가 5보다 작으면 아예 불가능
    if(k<5){
        cout << 0 <<endl;
        return 0;
    }
    
    // 접두어, 접미사는 무조건 배움
    alpha['a' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['c' - 'a'] = true;
    
    // 접두어, 접미사는 무조건 배우게
    k-=5;
    
    dfs(0,0);
    
    cout << ans << endl;

  
    return 0;
}
