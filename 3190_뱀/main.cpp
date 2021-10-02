//
//  main.cpp
//  3190_뱀
//
//  Created by 이동훈 on 2020/11/12.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int map[MAX][MAX];
vector<pair<int, char>> convert;

// 동 남 서 북
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0};

// 방향을 바꿔주는 함수
int turn_direction(int dir, char turn){
    int next_dir;
    if(turn == 'L'){
        next_dir = (dir + 3)%4;
    }
    else{
        next_dir = (dir +1)%4;
    }
    return next_dir;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, l;
    
    cin >> n >> k;
    
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        x = x-1;
        y = y-1;
        
        map[x][y] = 1;
    }
    
    cin >> l;
    
    for(int i=0;i<l;i++){
        int a;
        char c;
        
        cin >> a >> c;
        convert.push_back(make_pair(a,c));
    }
    
    int time = 0;           // 현재의 시간
    int dir = 0;            // 뱀의 방향
    int idx =0;             // convert의 idx (오름차순이므로)
    int x = 0, y = 0;       // 뱀의 머리 위치
    
    deque<pair<int,int>> dq;
    dq.push_back(make_pair(0,0));
    map[x][y] = 2;
    
    while(1){
        time++;
        
        int next_x = x + dx[dir];
        int next_y = y + dy[dir];
        
        // 부딪히면 break
        if((next_x < 0 || next_x >= n || next_y < 0 || next_y >=n) || map[next_x][next_y] ==2)    {
            break;
        }
        
        // 사과가 없다면
        else if(map[next_x][next_y] == 0){
            map[next_x][next_y] = 2;                            // 뱀의 위치로
            map[dq.back().first][dq.back().second] = 0;         // 꼬리는 한칸 앞으로 (맵)
            dq.pop_back();                                      // 꼬리는 한칸 앞으로 (큐)
            dq.push_front(make_pair(next_x, next_y));           // 머리에 push
        }
        
        // 사과라면
        else if(map[next_x][next_y] == 1){
            map[next_x][next_y] = 2;                            // 뱀의 머리 (맵)
            dq.push_front(make_pair(next_x, next_y));           // 뱀의 머리 (큐)
        }
        
        // 변환해야하는 시간이라면 방향 바꿈
        if(idx < (int)convert.size()){
            if(time == convert[idx].first){
                dir = turn_direction(dir,convert[idx].second);
                idx++;
            }
        }
        x = next_x;
        y = next_y;
    }
    cout<< time << endl;
    
    return 0;
}

