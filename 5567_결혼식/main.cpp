//
//  main.cpp
//  5567_결혼식
//
//  Created by 이동훈 on 2020/08/24.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
using namespace std;

vector<vector<int>> friends;
vector<int> dis;
vector<bool> visited;
queue<int> q;
int n,m;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  friends.resize(n+1);
  visited.resize(n+1,false);
  dis.resize(n+1,999);
  dis[1] = 0;

  for(int i=0;i<m;i++){
    int person1,person2;
    cin >> person1 >> person2;

    friends[person1].push_back(person2);
    friends[person2].push_back(person1);
  }

  q.push(1);
  visited[1]=true;

  while(!q.empty()){
    int front = q.front();
    q.pop();

    int len = friends[front].size();
    for(int i=0;i<len;i++){
      int cur_friend = friends[front][i];
      if(!visited[cur_friend]) {
        visited[cur_friend] = true;
        dis[cur_friend] = dis[front]+1;
        q.push(cur_friend);
      }
    }
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(dis[i]<=2) cnt++;
  }
  cout<<cnt-1<<endl;

  return 0;
}
