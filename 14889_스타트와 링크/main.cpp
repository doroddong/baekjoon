//
//  main.cpp
//  14889_스타트와 링크
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

int n, ans=INF;
int s[21][21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> s[i][j];
        }
    }
    
    // 2^(n/2)-1 부터 2^n - 2^(n/2) 까지 수행
    // 예를 들어, n이 8이라면
    // 00001111 -> 15 부터
    // 11110000 -> 240 까지
    for(int i= (1<<n/2)-1 ; i<= (1<<n) - (1<<n/2);i++){
        vector<int> start, link;
        
        // 1이라면 start에, 0이라면 link에 푸시
        for(int j=0;j<n;j++){
            // i에서 j번째 인덱스가 1이라면
            if((i & (1<<j)) != 0) start.push_back(j+1);
            else link.push_back(j+1);
        }
        
        // 똑같이 반으로 나누어졌다면
        if(start.size() == n/2 && link.size() ==n/2){
            int start_sum=0;
            int link_sum=0;
            
            // 능력치 총 합 계산
            for(int i=0;i<n/2;i++){
                for(int j=i+1;j<n/2;j++){
                    if(i==j) continue;
                    
                    int start_first = start[i];
                    int start_second = start[j];
                    
                    start_sum += s[start_first][start_second] + s[start_second][start_first];
                    
                    int link_first = link[i];
                    int link_second = link[j];
                    
                    link_sum += s[link_first][link_second] + s[link_second][link_first];
                }
            }
            // 차이가 가장 최소인 지점 저장
            ans = min(ans, abs(start_sum-link_sum));
        }
    }
    
    cout<<ans <<endl;
    
    return 0;
}
