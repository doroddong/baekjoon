//
//  main.cpp
//  2947_나무조각
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


vector<int> tree_piece;

void execute_step(int step){
    if(tree_piece[step-1] > tree_piece[step]) {
        int temp;
        
        temp = tree_piece[step-1];
        tree_piece[step-1] = tree_piece[step];
        tree_piece[step] = temp;
        
        for(int i=0;i<tree_piece.size();i++){
            cout << tree_piece[i]<< " ";
        }
        cout <<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=0;i<5;i++){
        int piece;
        cin >> piece;
        
        tree_piece.push_back(piece);
    }
    
    while(1){
        bool exit_flag = true;
        for(int i=0;i<5;i++){
            if(tree_piece[i]!=i+1){
                exit_flag = false;
                break;
            }
        }
        if(exit_flag) break;
        
        execute_step(1);
        execute_step(2);
        execute_step(3);
        execute_step(4);
    }

    return 0;
}

