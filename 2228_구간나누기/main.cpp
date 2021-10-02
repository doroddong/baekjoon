//
//  main.cpp
//  2228_구간나누기
//
//  Created by 이동훈 on 2020/08/24.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
#define MIN -3276900
#define MAX 32768

using namespace std;

int n,m;
int dp[101][51];
int arr[101];

int divide_part(int n,int m){
  if(m==0) return 0;
  if(n<=0) return MIN;
  if(dp[n][m]!=-1) return dp[n][m];

  int sum =0;
  dp[n][m] = divide_part(n-1,m);
  for(int i=n;i>0;i--){
    sum+=arr[i];
    int temp = divide_part(i-2,m-1) + sum;
    if(temp>dp[n][m]) dp[n][m] = temp;
  }
  return dp[n][m];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> arr[i];
  }
  
  memset(dp,-1,sizeof(dp));

  cout<< divide_part(n,m) << endl;
  
  return 0;
}
