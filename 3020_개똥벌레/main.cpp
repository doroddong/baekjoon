//
//  main.cpp
//  3020_개똥벌레
//
//  Created by 이동훈 on 2020/09/09.
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
#define MAX 200000
#define INF 987654321
#define endl "\n"

using namespace std;

int n, h;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> h;
    
    vector<int> bottom(n/2), top(n/2);
    
    for(int i=0;i<n/2;i++){
        cin >> bottom[i] >> top[i];
    }
    sort(bottom.begin(),bottom.end());
    sort(top.begin(),top.end());
    
    int min_value = MAX+1;
    int cnt =0;
    for(int i=1;i<=h;i++){
        int bottom_cnt =0;
        int start =0;
        int end = bottom.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            
            if(bottom[mid] >= i){
                bottom_cnt = bottom.size() - mid;
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        
        start =0;
        end = top.size()-1;
        int top_cnt=0;
        while(start<=end){
            int mid = (start+end)/2;
            
            if(top[mid] > h-i){
                top_cnt = top.size() - mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        int temp = top_cnt + bottom_cnt;
        
        if(min_value == temp){
            cnt++;
        }
        else if(min_value > temp){
            min_value = temp;
            cnt=1;
        }
    }
    
    cout<<min_value << " " << cnt<<endl;
  
    return 0;
}
