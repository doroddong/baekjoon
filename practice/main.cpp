//
//  main.cpp
//  practice
//
//  Created by 이동훈 on 2021/10/04.
//  Copyright © 2021 이동훈. All rights reserved.
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

int main(){
//    vector<int> v{0, 0, 1, 1};
//    sort(v.begin(), v.end());
//
//    do {
//        for(auto it = v.begin(); it != v.end() ; ++it){
//            cout << *it << ' ';
//        }
//        cout << endl;
//    } while (next_permutation(v.begin(), v.end()));
    
//    vector<int> v{1,1,0,0};
//
//    do {
//        for (auto it = v.begin() ; it != v.end(); ++it){
//            cout << *it << ' ';
//        }
//        cout << endl;
//    } while (prev_permutation(v.begin(), v.end()));
    
    vector<int> s{1,2,3,4};
    vector<int> temp {1, 1, 0, 0};
    
    do {
        for (int i=0; i < s.size();i++){
            if(temp[i] == 1) cout << s[i] << ' ';
        }
        cout << endl;
    } while (prev_permutation(temp.begin(), temp.end()));
    
    return 0;
}


