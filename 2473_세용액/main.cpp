//
//  main.cpp
//  2473_세용액
//
//  Created by 이동훈 on 2020/09/01.
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
#include <climits>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 5001
#define MIN 1000000001
#define endl "\n"

using namespace std;

int n;
long long arr[MAX];
long long ans[3];
long long min_value;

void three_sum(){
    // i 를 반복
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        
        // 무한 반복
        while(1){
            // j가 k보다 크거나 같으면 반복문 종료
            if(j>=k)    break;
            
            // 세 값을 sum
            long long x = arr[i] + arr[j] + arr[k];
            // 기준이 0이므로 절댓값 계산
            long long abs_x = abs(x);
            
            // 현재의 최소보다 작다면 갱신
            if(min_value > abs_x){
                min_value = abs_x;
                ans[0] = arr[i];
                ans[1] = arr[j];
                ans[2] = arr[k];
            }
            
            // x보다 크다면 k를 -1
            if(x>0) k--;
            // x보다 작거나 같으면 j를 +1
            else    j++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    // 정렬
    sort(arr,arr+n);
    min_value =__LONG_LONG_MAX__;
    
    three_sum();
    
    for(int i=0;i<3;i++)    cout<<ans[i]<<" ";
    cout<<endl;
  
    return 0;
}
