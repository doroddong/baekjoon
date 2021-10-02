//
//  main.cpp
//  2533_사회망서비스
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
#include <cmath>
#include <cstdio>
#include <vector>

#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX_NODE 100001

using namespace std;

vector<vector<int>> tree;
int dp_table[1000001][2];
int n;

int dp(int cur,int pre, int state){
    // 이미 dp_table로 만들었다면 return
  if(dp_table[cur][state]!=-1) return dp_table[cur][state];

  int ans =0;
    
    //현재가 얼리어답터가 아니라면
  if(state==0){
    int len = tree[cur].size();
    
      // 현재와 이어진 next들의 dp를 리턴ㄴ
    for(int i=0;i<len;i++){
      int next = tree[cur][i];
      if(next==pre) continue;
      ans += dp(next,cur,1);
    }
    // 값을 저장
    dp_table[cur][state] = ans;
  }

    //현재가 얼리어답터라면
  else{
    int len = tree[cur].size();
    int temp1=0,temp2=0;
    for(int i=0;i<len;i++){
      int next = tree[cur][i];
      if(next==pre) continue;
        
        // 다음이 얼리어답터거나 아닐 때 temp를 구해서 min 값을 저장
      temp1 = dp(next,cur,0);
      temp2 = dp(next,cur,1);
      ans += min(temp1,temp2);
    }
      // 자기 자신을 포함하여 ans+1 해서 저장
    dp_table[cur][state] = ans+1;
  }
  return dp_table[cur][state];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  tree.resize(n+1);
  memset(dp_table,-1,sizeof(dp_table));
  for(int i=0;i<n-1;i++){
    int parent, child;
    cin >> parent >> child;

    tree[parent].push_back(child);
    tree[child].push_back(parent);
  }
    
// 첫번쨰 노드를 얼리어답터로 설정할건지 아닐건지 따로 해서 최소
  int ans = min(dp(1,0,0),dp(1,0,1));
  cout<<ans<<endl;
  
  return 0;
}
