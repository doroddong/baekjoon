//
//  main.cpp
//  2250_트리의높이와너비
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

#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX_NODE 10001

using namespace std;

int n, node_idx;
int child_num[MAX_NODE];
// depth 별 가정 왼쪽과 오른쪽 저장
int low[MAX_NODE];
int high[MAX_NODE];
// left 노드와 right 노드를 저장
pair<int,int> tree[MAX_NODE];

// Inorder Traversal (중위 순회)
void dfs(int node, int depth){

  // Left Subtree
  if(tree[node].first!=-1)  dfs(tree[node].first,depth+1);

  // 맨 왼쪽과 맨 오른쪽 확인
  low[depth] = min(low[depth],node_idx);
  high[depth] = max(high[depth],node_idx++);

  // Right Subtree
  if(tree[node].second!=-1) dfs(tree[node].second,depth+1);
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i=0;i<MAX_NODE;i++) low[i]=MAX_NODE;

  for(int i=0;i<n;i++){
    int parent, left_child, right_child;
    cin >> parent >> left_child >> right_child;

    child_num[parent]++;

    if(left_child!=-1)  child_num[left_child]++;
    tree[parent].first = left_child;
    if(right_child!=-1) child_num[right_child]++;
    tree[parent].second = right_child;
  }

  // Root 찾기
  int root;
  for(int i=1;i<=n;i++){
    if(child_num[i]==1) root = i;
  }

  // DFS - 중위 순회
  node_idx=1;
  dfs(root,1);

  // 최대 길이와 레벨
  int result =0, level=0;
  for(int i=1;i<=n;i++){
    int width = high[i]-low[i]+1;
    if(width > result){
      result = width;
      level  =i;
    }
  }

  cout<< level << " " <<result<<endl;

  return 0;
}
