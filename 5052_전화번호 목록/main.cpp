//
//  main.cpp
//  5052_전화번호 목록
//
//  Created by 이동훈 on 2020/09/29.
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
#define MAX 10001
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<string> s_arr(n);
        
        for(int i=0;i<n;i++){
            cin >> s_arr[i];
        }
        bool flag = false;
        
        // sort 하는 이유!!!
        //  15, 12, 1375, 1274, 1454 가 주어지면 sort하여
        //  12, 1274, 1375, 1454, 15 와 같은 순서로 정렬되고
        //  순차적으로만 검색할 수 있게 만들어줌
        //  따라서, 시간 복잡도는 O(n^2)에서 O(n)으로 줄일 수 있다.
        
        sort(s_arr.begin(),s_arr.end());
        
        for(int i=0;i<n-1;i++){
            
            // (i+1)번째 문자열에 i 번째 문자열이 포함된다면 flag 바꿔주고 break
            if(s_arr[i]== s_arr[i+1].substr(0,s_arr[i].size())){
                flag = true;
                break;
            }
        }
        if(flag) cout<< "NO" <<endl;
        else cout<<"YES"<<endl;
    }
  
    return 0;
}
