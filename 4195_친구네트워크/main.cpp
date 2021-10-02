//
//  main.cpp
//  4195_친구네트워크
//
//  Created by 이동훈 on 2020/09/03.
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
#include <map>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

int t;
int parent[MAX], setSize[MAX];

// find
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

// unite
void unite(int x, int y){
    x= find(x);
    y = find(y);
    
    // 서로 다른 집합이라면 x를 y에 합침. ( y 의 사이즈 증가 , x의 사이즈 1)
    if(x != y){
        parent[x] = y;
        setSize[y] += setSize[x];
        setSize[x] =1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    while(t--){
        
        int f;
        // 인덱싱을 위해 선언
        int count=1;
        
        // string을 key로 index를 가지는 map 생성
        map<string,int> friend_set;
        cin >> f;
        
        // 초기화
        for(int i=1;i<=MAX;i++){
            parent[i] = i;
            setSize[i] =1;
        }
        
        for(int i=0;i<f ; i++){
            string s1, s2;
            cin >> s1 >> s2;
            
            // 기존에 없다면 인덱싱한 후에 추가
            if(friend_set.count(s1)==0) friend_set[s1] = count++;
            if(friend_set.count(s2)==0) friend_set[s2] = count++;
            
            // unite 결과
            int temp1 = find(friend_set[s1]);
            int temp2 = find(friend_set[s2]);
            
            if(temp1 == temp2)  cout<< max(setSize[temp1],setSize[temp2])<<endl;
            else{
                unite(temp1, temp2);
                cout<< max(setSize[temp1],setSize[temp2])<<endl;
            }
        }
    }
    return 0;
}
