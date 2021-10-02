//
//  main.cpp
//  1063_킹
//
//  Created by 이동훈 on 2020/11/13.
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

// R L B T RT LT RB LB
int dx[8] = { 0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1};

int turn_dir(string s){
    if(s=="R")  return 0;
    else if (s=="L") return 1;
    else if(s=="B") return 2;
    else if(s=="T") return 3;
    else if(s=="RT") return 4;
    else if(s=="LT") return 5;
    else if(s=="RB") return 6;
    else return 7;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int king_x, king_y;
    int stone_x, stone_y;
    
    string king_xy, stone_xy;
    int n;
    
    cin >> king_xy >> stone_xy;
    cin >> n;
    
    king_x = abs(8 - (king_xy[1]- '0'));
    king_y = king_xy[0] - 'A';
    
    stone_x = abs(8 - (stone_xy[1]-'0'));
    stone_y = stone_xy[0]-'A';
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        
        int dir = turn_dir(s);
        
        int next_king_x = king_x + dx[dir];
        int next_king_y = king_y + dy[dir];
        
        // 킹이 밖으로 나가면 무시
        if(next_king_x<0 || next_king_x>=8 || next_king_y < 0 || next_king_y>=8) continue;
        
        // 돌과 킹이 같은 위치라면 돌을 방향대로
        if(stone_x == next_king_x && stone_y == next_king_y){
            int next_stone_x = stone_x + dx[dir];
            int next_stone_y = stone_y + dy[dir];
            
            // 돌의 위치가 밖이라면 무시
            if(next_stone_x<0 || next_stone_x>=8 || next_stone_y < 0 || next_stone_y >=8) continue;
            
            // 아니라면 돌의 위치 바꿈
            stone_x = next_stone_x;
            stone_y = next_stone_y;
        }
        
        // 킹의 위치 바꿈
        king_x = next_king_x;
        king_y = next_king_y;
    }
    
    string f_king_xy ="";
    f_king_xy = (king_y+65);
    f_king_xy += to_string(8-king_x);
    
    string f_stone_xy = "";
    f_stone_xy = (stone_y+65);
    f_stone_xy += to_string(8-stone_x);
    
    cout<< f_king_xy <<endl;
    cout<< f_stone_xy << endl;
    
    
    return 0;
}
