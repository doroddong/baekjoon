//
//  main.cpp
//  2539_모자이크
//
//  Created by 이동훈 on 2020/09/09.
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
#define MAX 1000000
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int x, y, possible_cnt, wrong_num,max_height=0;
vector<int> mistake;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> x >> y;
    
    cin >> possible_cnt >> wrong_num;
    
    for(int i=0;i<wrong_num;i++){
        int a,b;
        cin >> a>> b;
        max_height = max(max_height,a);
        mistake.push_back(b);
    }
    
    sort(mistake.begin(),mistake.end());
    
    // 최소 max_height부터 최대 MAX까지
    int l = max_height;
    int r = MAX;
    while(l<r){
        int mid = (l+r)/2;
        int cnt=0;
        int prev = -1;
        for(int i=0;i<mistake.size();i++){
            // 처음 종이를 놓는 경우, [prev, prev + mid)까지 커버 가능
            if(prev==-1){
                prev = mistake[i];   // 다음 위치
                cnt++;               // 종이 추가
            }
            else if( prev + mid <= mistake[i]){
                prev = mistake[i];        // 다음 위치
                cnt++;                    // 종이 추가
            }
        }
        // 종이가 충분한 경우, 더 작은 종이로 해봄
        if(cnt<=possible_cnt){
            r = mid;
        }
        // 종이가 불충분한 경우, 더 큰 종이로 해봄
        else{
            l = mid+1;
        }
    }
    cout << l <<endl;

    
    
    
    
    
    
    
  
    return 0;
}
