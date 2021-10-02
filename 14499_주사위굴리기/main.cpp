//
//  main.cpp
//  14499_주사위굴리기
//
//  Created by 이동훈 on 2020/10/07.
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

int n, m, k, x, y;
int map[20][20];
vector<int> dice(7);

// 동쪽 : 1, 서쪽 : 2, 북쪽 : 3, 남쪽 :4
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { 1, -1, 0, 0};

void roll_dice(int dir){
    //임시 배열 생성 후 복사
    int temp[7];
    
    for(int i=1;i<=6;i++){
        temp[i] = dice[i];
    }
    
    // 동쪽 : 1, 서쪽 : 2, 북쪽 : 3, 남쪽 :4
    if(dir==1){
        dice[1] = temp[4];
        dice[3] = temp[1];
        dice[4] = temp[6];
        dice[6] = temp[3];
    }
    else if(dir==2){
        dice[1] = temp[3];
        dice[3] = temp[6];
        dice[4] = temp[1];
        dice[6] = temp[4];
    }
    else if(dir==3){
        dice[1] = temp[5];
        dice[2] = temp[1];
        dice[5] = temp[6];
        dice[6] = temp[2];
    }
    else{
        dice[1] = temp[2];
        dice[2] = temp[6];
        dice[5] = temp[1];
        dice[6] = temp[5];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<k;i++){
        int dir;
        cin >> dir;
        
        // 해당 방향에 맞게
        int next_x = dx[dir-1]+x;
        int next_y = dy[dir-1]+y;
        
        // 가능한 벙위인지 확인
        if(next_x>=0 && next_x<n && next_y >=0 && next_y<m){
            roll_dice(dir);
            
            // 이동할 칸이 0이면, 주사위 바닥면에 쓰여있는 수를 칸에 복사
            if(map[next_x][next_y]==0){
                map[next_x][next_y] = dice[6];
            }
            // 아니라면, 칸의 수를 바닥면에 복사하고 칸은 0으로
            else{
                dice[6] = map[next_x][next_y];
                map[next_x][next_y] = 0;
            }
            // 좌표 바꿔준 후 출력
            x = next_x;
            y = next_y;
        
            cout << dice[1] <<endl;
        }
    }
    
    return 0;
}

