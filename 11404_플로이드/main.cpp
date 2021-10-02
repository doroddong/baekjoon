//
//  main.cpp
//  11404_플로이드
//
//  Created by 이동훈 on 2020/08/24.
//  Copyright © 2020 이동훈. All rights reserved.
//
// #include <iostream>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <set>
// #include <queue>
// #define inRange(x,y,max_x,max_y) ((1<=x) && (x<=max_x) && (1<=y) && (y<=max_y))
// #define INF 100001
// using namespace std;

// int n,m;
// int city[101][101];

// int main(){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0); cout.tie(0);

//   cin >> n >> m;

//   for(int i=1;i<=n;i++){
//     for(int j=1;j<=n;j++){
//       city[i][j]=INF;
//     }
//   }
  
//   for(int k=0;k<m;k++){
//     int i, j;
//     int dist;
//     cin >> i >> j >> dist;

//     if(city[i][j]>dist){
//       city[i][j] = dist;
//     }
//   }
//   for(int k=1;k<=n;k++){
//     for(int i=1;i<=n;i++){
//       for(int j=1;j<=n;j++){
//         if(city[i][k]!=INF && city[k][j]!=INF){
//           if((city[i][k] + city[k][j] < city[i][j])){
//             city[i][j] = city[i][k] + city[k][j];
//           }
//         }
//       }
//     }
//   }

//   for(int i =1;i<=n;i++){
//     for(int j=1;j<=n;j++){
//       if(i==j || city[i][j]==INF){
//         cout<< "0 ";
//       }
//       else  {
//         cout << city[i][j]<< " ";
//       }
//     }
//     cout<<endl;
//   }

//   return 0;
// }


#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 987654321
#define ARR_SIZE 100 + 1
int vertex, edge;
int arr[ARR_SIZE][ARR_SIZE];
int from, to, weight;
 
void floyd_warshall() {
    for (int i = 1; i <= vertex; i++)
        for (int j = 1; j <= vertex; j++)
            for (int k = 1; k <= vertex; k++)
                if (arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}
 
int main(){
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < edge; i++) {
        cin >> from >> to >> weight;
        if (arr[from][to] > weight)
            arr[from][to] = weight;
    }
    floyd_warshall();
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if ( i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
