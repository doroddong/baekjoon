//
//  main.cpp
//  17144_미세먼지안녕
//
//  Created by 이동훈 on 2020/08/31.
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
#define MAX 50
#define INF 987654321
#define endl "\n"

using namespace std;

int r,c,t, answer;
int map[MAX][MAX];
vector<pair<int,int>> air;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1};

// 위쪽 공기청정기의 바람 방향 ( 동, 북, 서, 남)
int upper_dir_x[4] = { 0, -1, 0, 1};
int upper_dir_y[4] = { 1, 0, -1, 0};

// 아래쪽 공기청정기의 바람 방향 (동, 남, 서, 북)
int lower_dir_x[4] = { 0, 1, 0, -1};
int lower_dir_y[4] = { 1, 0, -1, 0};


void spread_out(){
    // mask 초기화. ( map으로 바로 반영시킨다면 그때그때 값이 바뀜 -> 변경만을 위한 변수 선언)
    int mask[r][c];
    memset(mask,0,sizeof(mask));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            // 미세먼지가 있다면
            if(map[i][j]!=0 && map[i][j]!=-1){
                // 확산 빈도 체크
                int spread_cnt =0;
                
                // 인접한 위치 체크
                for(int k=0;k<4;k++){
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];
                    
                    // 범위 안이고 공기청정기가 아닌 경우 -> 확산 발생
                    if(inRange(next_x, next_y, r, c) && map[next_x][next_y] != -1){
                        spread_cnt++;
                        mask[next_x][next_y] += map[i][j]/5;
                    }
                }
                // 확산한 빈도만큼 map에서 빼줌
                map[i][j] = map[i][j] - (map[i][j]/5) * spread_cnt;
            }
        }
    }
//    cout<<"---------mask----------"<<endl;
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout<< mask[i][j] <<" ";
//        }
//        cout<<endl;
//    }
    
    // 확산 결과 반영
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            map[i][j] += mask[i][j];
        }
    }
}

void clean_air(){
    int upper_air_x = air[0].first;
    int upper_air_y = air[0].second;
    
    int lower_air_x = air[1].first;
    int lower_air_y = air[1].second;
    
    // 위쪽 공기 청정기
    queue<pair<int,int>> q;
    q.push(make_pair(upper_air_x, upper_air_y));
    int dir = 0;    // 방향 체크
    int prev = 0;   // 이전 값
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        while(1){
            // 오버플로우 방지, 빠져나갈 조건
            if(dir==4) break;
            // 다음 위치
            int next_x = cur_x + upper_dir_x[dir];
            int next_y = cur_y + upper_dir_y[dir];
            
            // 갈수 있음
            if(inRange(next_x,next_y,r,c)){
                // 다음이 -1이 아닌 경우 -> 바꿔줌
                if(map[next_x][next_y] != -1){
                    int temp = map[next_x][next_y];
                    map[next_x][next_y] = prev;
                    prev = temp;
                    q.push(make_pair(next_x,next_y));
                }
                // 옮기는 처리를 했으므로 반복문 종료
                break;
            }
            // 갈수 없음 -> 방향 틀기
            else{
                dir++;
            }
        }
    }
    
    // 아래 공기 청정기 (위쪽 공기 청정기와 동일)
    q.push(make_pair(lower_air_x,lower_air_y));
    dir = 0 ;
    prev = 0;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        while(1){
            if(dir==4)  break;
            int next_x = cur_x + lower_dir_x[dir];
            int next_y = cur_y + lower_dir_y[dir];
            
            if(inRange(next_x, next_y, r,c)){
                if(map[next_x][next_y] != -1){
                    int temp = map[next_x][next_y];
                    map[next_x][next_y] = prev;
                    prev=temp;
                    q.push(make_pair(next_x,next_y));
                }
                break;
            }
            else{
                dir++;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
            // 공기청정기 위치 저장
            if(map[i][j] == -1){
                air.push_back(make_pair(i, j));
            }
        }
    }
    
    // t만큼 확산과 공기청정기 작동 반복
    while(t--){
        spread_out();
        clean_air();
    }
    
    int ans=0;
//    cout<<"---------map-------"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
//            cout<< map[i][j] << " ";
            if(map[i][j]!=-1)   ans+=map[i][j];
        }
//        cout<<endl;
    }

    cout<< ans <<endl;
    return 0;
}
