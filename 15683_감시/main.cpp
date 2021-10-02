//
//  main.cpp
//  15683_감시
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

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct CCTV
{
    int type, x, y;
    // 생성자
    CCTV(int type, int x, int y) : type(type), x(x), y(y) {};
};

int n,m, ans = INF;
int map[8][8];
// cctv 종류당 가지 수
int rotation[] = {NULL, 4,2,4,4,1};
vector<CCTV> cctv;

void copy_map(int desc[8][8], int src[8][8]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            desc[i][j] = src[i][j];
        }
    }
}

// 한 방향으로만 감시
void moniter(int dir, CCTV cctv){
    
    //cctv를 기준으로 dir 방향에 대한 감시 수행
    // dir = 0 :동, 1:북, 2: 서, 3:남
    dir %=4;    //dir값이 4보다 큰 값이 올수도 있음
    
    // 벽을 만나면 break;
    // 감시 가능하면 -1로
    if(dir ==0){            //동쪽
        for(int y=cctv.y+1;y<m;y++){
            if(map[cctv.x][y]==6) break;
            map[cctv.x][y] = -1;
        }
    }
    else if(dir ==1){       // 북쪽
        for(int x=cctv.x-1;x>=0;x--){
            if(map[x][cctv.y]==6) break;
            map[x][cctv.y] = -1;
        }
    }
    else if(dir==2){        // 서쪽
        for(int y=cctv.y-1;y>=0;y--){
            if(map[cctv.x][y]==6) break;
            map[cctv.x][y] = -1;
        }
    }
    else{                   // 남쪽
        for(int x=cctv.x+1;x<n;x++){
            if(map[x][cctv.y] == 6) break;
            map[x][cctv.y] = -1;
        }
    }
}

void dfs(int cnt){
    
    // cctv 끝까지 왔으면 사각지대 계산
    if(cnt == cctv.size()){
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] == 0 )     cnt++;
            }
        }
        if(ans > cnt){
            ans= cnt;
        }
        return;
    }
    
    int backup[8][8];
    int type = cctv[cnt].type;
    
    // cctv의 type의 경우의 수만큼 반복
    for(int dir=0;dir<rotation[type];dir++){
        
        // 백업
        copy_map(backup,map);
        
        if(type ==1){           // 1번 카메라는 한 방향 감시
            moniter(dir,cctv[cnt]);
        }
        else if(type==2) {      // 2번 카메라는 한 방향과 반대방향
            moniter(dir,cctv[cnt]);
            moniter(dir+2,cctv[cnt]);
        }
        else if(type==3){       // 3번 카메라는 한 방향과 수직방향
            moniter(dir,cctv[cnt]);
            moniter(dir+1,cctv[cnt]);
        }
        else if(type==4){       // 4번 카메라는 한 방향, 수직, 반대 방향
            moniter(dir,cctv[cnt]);
            moniter(dir+1,cctv[cnt]);
            moniter(dir+2, cctv[cnt]);
        }
        else if (type==5){      // 5번 카메라는 모든 방향
            moniter(dir,cctv[cnt]);
            moniter(dir+1,cctv[cnt]);
            moniter(dir+2,cctv[cnt]);
            moniter(dir+3,cctv[cnt]);
        }
        
        // 다음 카메라로 넘어감
        dfs(cnt+1);
        
        // 복원 - 백트래킹
        copy_map(map, backup);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] !=0 && map[i][j]!=6){
                cctv.push_back(CCTV(map[i][j],i,j));
            }
        }
    }
    dfs(0);
    cout<<ans<<endl;
  
    return 0;
}
