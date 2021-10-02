//
//  main.cpp
//  1022_소용돌이 이쁘게 출력하기
//
//  Created by 이동훈 on 2020/10/06.
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
#include <iomanip>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int arr[50][5];
int r1,c1,r2,c2;

int dx[4] = { 0, -1, 0, 1};
int dy[4] = { 1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> r1 >> c1 >> r2 >> c2;
    
    int x = 0;
    int y = 0;
    int max_cnt = 1;
    int cur = 1;
    int cnt = 0;
    int dir=0;
    
    while(!arr[0][0] || !arr[0][c2-c1] || !arr[r2-r1][0] || !arr[r2-r1][c2-c1]){
        
        if(x-r1 >=0 && x-r1 <= (r2-r1) && y-c1>=0 && y-c1 <= (c2-c1)){
            arr[x-r1][y-c1] = cur;
        }
        
        cnt++;
        cur++;
        
        
        x += dx[dir];
        y += dy[dir];
        
        if(cnt == max_cnt){
            cnt=0;
            dir = (dir+1) % 4;
            if(dir == 0 || dir ==2) {
                max_cnt ++;
            }
        }
    }
    
    cnt=0;
    while(cur){
        cur /=10;
        cnt++;
    }
    
    for(int i=0;i<r2-r1+1 ;i++){
        for(int j=0;j<c2-c1+1;j++){
            cout << setw(cnt) <<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
  
    return 0;
}

