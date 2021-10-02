//
//  main.cpp
//  2660_회장뽑기
//
//  Created by 이동훈 on 2020/09/02.
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
#define MAX 51
#define INF 987654321
#define endl "\n"

using namespace std;

int arr[MAX][MAX],  max_value[MAX];
vector<int> candidate;
int min_dist, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = (i==j) ? 0 : INF;
        }
    }
    
    
    while(1){
        int from, to;
        cin >> from >> to;
        if(from == -1 && to == -1)  break;
        
        arr[from][to] =1;
        arr[to][from] =1;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
//                    for(int p=0;p<candidate.size()-1;p++){
//                        candidate.pop_back();
//                    }
//                    candidate.push_back(k);
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        max_value[i] = -INF;
    }
    int boss=-1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j] > max_value[i]){
                max_value[i] = arr[i][j];
            }
        }
        if(max_value[i] < boss || boss == -1) boss = max_value[i];
    }
    
    int cnt =0;
    for(int i=1;i<=n;i++){
        if(max_value[i] == boss) cnt++;
    }
    
    cout<< boss << " "<<cnt<<endl;

    for(int i=1;i<=n;i++){
        if(max_value[i] ==boss) cout<< i << " ";
    }
    cout<<endl;
    
    
  
    return 0;
}
