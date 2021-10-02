//
//  main.cpp
//  1256_사전
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
#include <climits>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m,k;

// 첫번째 인자 : n과 m의 총합 개수(n+m)
// 두번째 인자 : a의 개수(n)
// 즉, n+m 개의 길이에서 a의 개수는 n이고 z의 개수는 m 에서 만들수 있는 스트링 개수 (중복 조합)
ll str_number[201][201];         // n,m이 각각 최대 100이므로 201로 선언


ll lim;                 // 만들 수 있는 문자열 수

ll return_str_number(int a, int b) {
    return str_number[a+b][b];
}

void dfs(int i, int j, ll cnt, int len){
    // 길이가 0이라면 리턴
    if(len==0)  return;
    
    // a의 개수가 0이면,
        // z를 출력하고
        // cnt에다가 str[i+j-1][j]를 빼준 dfs ( 그 이유는 z를 출력한 다음 뒷 문자에 대한 순서가 달라짐)
    if(i==0){
        cout<<'z';
        dfs(i,j-1,cnt-return_str_number(i-1,j),len-1);
    }
    // z의 개수가 0이면,
        // a를 출력하고
        // cnt는 그대로 수행
        // (그 이유는 a를 출력한 다음 뒷 문자에 대한 순서가 달라지지 않음)
    else if(j==0){
        cout<<'a';
        dfs(i-1,j,cnt,len-1);
    }
    // str[i+j-1][j]이 cnt보다 크다면(중복 조합의 크기가 만들려는 개수보다 크기 때문에)
        // 무조건 a를 출력해줘야하고,
        // cnt 그대로 (이유는 위와 같음)
    else if(return_str_number(i-1,j) >= cnt){
        cout<<'a';
        dfs(i-1,j,cnt,len-1);
    }
    else{
        cout<<'z';
        dfs(i,j-1,cnt-return_str_number(i-1,j),len-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    cin >> n >> m >> k;
    
    str_number[1][0] = str_number[1][1] = 1;
    for(int i=2;i<=200;i++){
        for(int j=0;j<=i;j++){
            // 1e9+1 은 10^9 +1
            str_number[i][j] = min((ll)1e9+1,str_number[i-1][j]+str_number[i-1][j-1]);
        }
    }
    
    lim = return_str_number(n,m);
    if(k>lim) {
        cout<<-1<<endl;
        return 0;
    }
    
    dfs(n,m,k,n+m);
    cout<<endl;
    
  
    return 0;
}
