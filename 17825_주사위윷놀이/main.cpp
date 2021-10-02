//
//  main.cpp
//  17825_주사위윷놀이
//
//  Created by 이동훈 on 2020/09/14.
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

vector<pair<int,int>> horse(4,make_pair(0,0));
int dice[10];

int map[4][22] = {
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,},
    {10,13,16,19,25,30,35,40,0,},
    {20,22,24,25,30,35,40,0,},
    {30,28,27,26,25,30,35,40,0,}
};
bool check[4][22];

int max_sum = -1;


void dfs(int cnt, int sum){
    if(cnt==10){
        max_sum = max(max_sum,sum);
        return;
    }
    
    for(int i=0;i<horse.size();i++){
        int prev_route = horse[i].first;
        int prev_loc = horse[i].second;
        
        int move = dice[cnt];
        
        if((prev_route==0 && prev_loc>=21)
           || (prev_route==1 && prev_loc >=9)
           || (prev_route==2 && prev_loc >=7)
           || (prev_route==3 && prev_loc >=8))  continue;
        
        int next_loc;
        int next_route;
        if(prev_route==0){
            if(prev_loc == 5){
                next_route = 1;
                next_loc =move;
            }
            else if(prev_loc == 10) {
                next_route =2;
                next_loc =move;
            }
            else if(prev_loc ==15){
                next_route = 3;
                next_loc =move;
            }
            else{
                next_route = 0;
                next_loc = prev_loc+move;
            }
        }
        else{
            next_route = prev_route;
            next_loc = prev_loc+move;
        }
        
        if(check[next_route][next_loc]==true) continue;
        
//        if((next_route==0 && next_loc>=21)
//        || (next_route==1 && next_loc >=9)
//        || (next_route==2 && next_loc >=7)
//        || (next_route==3 && next_loc >=8))  continue;
        
        if((next_route==1 && next_loc==4)
           || (next_route==2 && next_loc ==3)
           || (next_route==3 && next_loc ==4)){
            check[1][4] = true;
            check[2][3] = true;
            check[3][4]= true;
        }
        else{
            check[next_route][next_loc] = true;
        }
        
        if((prev_route==1 && prev_loc==4)
        || (prev_route==2 && prev_loc ==3)
           || (prev_route==3 && prev_loc ==4)){
            check[1][4] = false;
            check[2][3] = false;
            check[3][4]= false;
        }
        else{
            check[prev_route][prev_loc] = false;
        }
        
//        check[prev_route][prev_loc] = false;
//        check[next_route][next_loc] = true;
        horse[i] = make_pair(next_route,next_loc);
        
        dfs(cnt+1, sum+ map[next_route][next_loc]);
        
        horse[i] = make_pair(prev_route,prev_loc);
//        check[prev_route][prev_loc] = true;
//        check[next_route][next_loc] = false;
        
        if((next_route==1 && next_loc==4)
        || (next_route==2 && next_loc ==3)
           || (next_route==3 && next_loc ==4)){
            check[1][4] = false;
            check[2][3] = false;
            check[3][4]= false;
        }
        else{
            check[next_route][next_loc] = false;
        }
        
        if((prev_route==1 && prev_loc==4)
        || (prev_route==2 && prev_loc ==3)
           || (prev_route==3 && prev_loc ==4)){
            check[1][4] = true;
            check[2][3] = true;
            check[3][4]= true;
        }
        else{
            check[prev_route][prev_loc] = true;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    for(int i=0;i<10;i++){
        cin >> dice[i];
    }
    
    dfs(0,0);
    
    cout<< max_sum <<endl;
    return 0;
}
