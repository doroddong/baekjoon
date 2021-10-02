//
//  main.cpp
//  11723_집합
//
//  Created by 이동훈 on 2020/10/02.
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

int bitmask=0;

void add(){
    int idx;
    cin >> idx;
    bitmask  |= ( 1 << idx);
}
void remove(){
    int idx;
    cin >> idx;
    bitmask &= ~( 1 << idx);
}
void check(){
    int idx;
    cin >> idx;
    cout << ((bitmask & (1 << idx)) ? 1 : 0) << endl;
}

void toggle(){
    int idx;
    cin >> idx;
    bitmask ^= ( 1<< idx);
}

void all(){
    bitmask = (1<<21)-1;
}

void empty () {
    bitmask = 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m;
    cin >> m;
    
    for(int i=0;i<m;i++){
        string oper;
        cin >> oper;
        
        if(oper=="add")     add();
        else if(oper=="check") check();
        else if(oper == "remove")   remove();
        else if (oper == "toggle")  toggle();
        else if(oper == "all")  all();
        else if(oper == "empty") empty();
    }

  
    return 0;
}
