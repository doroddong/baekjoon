////
////  main.cpp
////  10836_여왕벌
////
////  Created by 이동훈 on 2020/09/02.
////  Copyright © 2020 이동훈. All rights reserved.
////
//
//#include <iostream>
//#include <cstring>
//#include <string>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <cmath>
//#include <cstdio>
//
//#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
//#define swap(a,b) {int t = a; a=b; b=t;}
//#define MAX 701
//#define INF 987654321
//#define endl "\n"
//
//using namespace std;
//
//int n , m;
//int arr[MAX][MAX];
//int g[3] = {0, 1, 2};
//vector<int> out;
//
//void grow_up(){
//    int cnt_zero , cnt_one, cnt_two;
//    cin >> cnt_zero >> cnt_one >> cnt_two;
//
//    for(int i=cnt_zero; i<cnt_zero+cnt_one ;i++){
//        out[i]++;
//    }
//    for(int i = cnt_zero + cnt_one ; i<2*m-1;i++){
//        out[i]+=2;
//    }
//}
//
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//
//    cin >> m >> n;
//    out.resize(2*m-1,1);
//
//
//    for(int i=0;i<n;i++){
//        grow_up();
//    }
//
//    for(int i=0;i<m;i++){
//        for(int j=0 ; j< m;j++){
//            if(j==0) cout<< out[
//        }
//    }
//
//
//    return 0;
//}


//
//  main.cpp
//  10836_여왕벌
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
#define MAX 701
#define INF 987654321
#define endl "\n"

using namespace std;

int n , m;
int arr[MAX][MAX];
int g[3] = {0, 1, 2};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n;
    
    
    for(int i=0;i<n;i++){
        int cnt_zero , cnt_one, cnt_two;
        cin >> cnt_zero >> cnt_one >> cnt_two;
        
        int inc=-1;
        
        for(int i=m;i>0;i--){
            if(cnt_zero){
                inc = 0;
                cnt_zero--;
            }
            else if(cnt_one) {
                inc =1;
                cnt_one--;
            }
            else if(cnt_two) {
                inc =2;
                cnt_two--;
            }
            
            arr[i][1] += g[inc];
        }
        
        for(int i=2 ; i<=m ;i++){
            if(cnt_zero){
                inc = 0;
                cnt_zero--;
            }
            else if(cnt_one) {
                inc =1;
                cnt_one--;
            }
            else if(cnt_two) {
                inc =2;
                cnt_two--;
            }
            arr[1][i] += g[inc];
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(j==1) cout<<arr[i][j]+1<<" ";
            else cout<< arr[1][j]+1<< " ";
        }
        cout<< endl;
    }
  
    return 0;
}
