//
//  main.cpp
//  2610_회의준비
//
//  Created by 이동훈 on 2020/08/26.
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
#define MAX 101
#define INF 987654321
#define endl "\n"

using namespace std;

int n, k;
bool visited[MAX];
int arr[MAX][MAX];
vector<int> s[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = INF;
        }
    }
    
    for(int i=0;i<k;i++){
        int from , to;
        cin >> from >> to;
        arr[from][to] = 1;
        arr[to][from] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]> arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    int len =0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            len++;
            visited[i]=true;
            for(int j=1;j<=n;j++){
                if(arr[i][j]<INF && i!=j){
                    s[len].push_back(j);
                    visited[j] =true;
                }
            }
        }
    }
    
    for(int i=1;i<=s[i].size();i++){
        int temp = s[i][
        for(int j=1;j<=n;j++){
            if()
        }
    }
    
    
    
    
    
    
    
    return 0;
}
