//
//  main.cpp
//  1936_소수경로
//
//  Created by 이동훈 on 2020/08/25.
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
#define MAX_NODE 100001
#define INF 987654321
#define endl "\n"

using namespace std;

int t;
bool arr[10000];
bool visitied[10000];

// 소수 판별 (에라토스테네스의 체)
void get_che(){
    for(int i=2; i*i<10000; i++){
        for(int j=i*i; j<10000; j+=i){
            arr[j] = false;
        }
    }
}

int bfs(int start, int dest){
    
    queue<pair<int,int>> q;
    q.push(make_pair(start,0));
    visitied[start]= true;
    
    while(!q.empty()){
        int cur_value = q.front().first;
        int cur_count = q.front().second;
        q.pop();
        
        if(cur_value == dest){
            return cur_count;
        }
        
        // 각 자리수를 계산
        int x4 = cur_value/1000;
        int x3 = (cur_value/100)%10;
        int x2 = (cur_value/10)%10;
        int x1 = cur_value%10;
        
        // 각 자리수마다 하나씩만 바꿔서 아직 방문하지 않았고 소수이면 큐에 푸시
        for(int i=0;i<=9;i++){
            int next_x = cur_value - x4*1000 + 1000*i;
            
            if(next_x>=1000 && next_x<10000 && !visitied[next_x] && arr[next_x]){
                visitied[next_x] =true;
                q.push(make_pair(next_x,cur_count+1));
            }
        }
        for(int i=0;i<=9;i++){
            int next_x = cur_value - 100*x3+100*i;
            if(next_x>=1000 && next_x<10000 && !visitied[next_x] && arr[next_x]){
                visitied[next_x] =true;
                q.push(make_pair(next_x,cur_count+1));
            }
        }
        for(int i=0;i<=9;i++){
            int next_x = cur_value - 10*x2+10*i;
            if(next_x>=1000 && next_x<10000 && !visitied[next_x]&& arr[next_x]){
                visitied[next_x] =true;
                q.push(make_pair(next_x,cur_count+1));
            }
        }
        for(int i=0;i<=9;i++){
            int next_x = cur_value - x1+i;
            if(next_x>=1000 && next_x<10000 && !visitied[next_x] && arr[next_x]){
                visitied[next_x] =true;
                q.push(make_pair(next_x,cur_count+1));
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    get_che();
    cin >> t;
    
    while(t--){
        int start , dest;
        cin >> start >> dest;
        
        for(int i=1000;i<10000;i++){
            visitied[i] =false;
        }
        
        int result = bfs(start,dest);
        if(result==-1)    cout<<"Impossible"<<endl;
        else    cout<<result<<endl;
    }
  
    return 0;
}
