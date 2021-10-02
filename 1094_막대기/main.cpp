//
//  main.cpp
//  1094_막대기
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


// bit 연산을 통해 이진법으로 1의 개수를 세면 막대의 개수가 니온다.

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int ans=0, x;
    
    cin >> x;
    
    // x가 0보다 클 때 까지 반복
    while(x>0){
        // 현재 2^0의 자리가 있다면 ans++
        if(x & 1) ans++;
        
        // 오른쪽으로 shift
        x >>= 1;
    }
    
    cout<< ans<<endl;
  
    return 0;
}
