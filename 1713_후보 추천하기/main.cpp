//
//  main.cpp
//  1713_후보 추천하기
//
//  Created by 이동훈 on 2020/11/13.
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

int n, k;

// 추천 받은 수, 순서, 추천받은 학생 넘버,

// (추천 받은수 - 순서)로 내림차순 정렬
bool compare_cnt(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.first != b.first.first){
        return a.first.first > b.first.first;
    }
    return a.first.second > b.first.second;
}

// (학생 번호) 로 오름차순 정렬
bool compare_student(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    cin >> k;
    
    vector<pair<pair<int,int>,int>> v;
    
    int cnt =1;                             // 들어온 순서
    for(int i=0;i<k;i++){
        int cur_student;
        cin >> cur_student;
        
        bool in_flag = false;
        
        // 이미 존재하는 추천이 있으면
        for(int j=0;j<v.size();j++){
            if(cur_student == v[j].second){
                v[j].first.first++;
                in_flag = true;
                break;
            }
        }
        
        // 이미 존재하는 추천이 없다면
        if(!in_flag){
            // 꽉 차 있으면 추천이 최소인 학생
            if(v.size()==n){
                v[n-1].first.first = 0;
                v[n-1].first.second = cnt;
                v[n-1].second = cur_student;
            }
            // 꽉 차 있지 않으면 push
            else{
                v.push_back(make_pair(make_pair(0,cnt),cur_student));
            }
        }
        
        sort(v.begin(),v.end(),compare_cnt);
                                  
        cnt++;
    }
    
    sort(v.begin(),v.end(),compare_student);
    for(int i=0;i<v.size();i++){
        cout << v[i].second << " ";
    }
    cout<< endl;
    
    return 0;
}

