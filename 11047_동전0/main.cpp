//
//  main.cpp
//  11047_동전0
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    int coin = 0;
    int cost[11];

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> cost[i];

    for (int i = N - 1; i >= 0; i--) {
        if (K == 0)
            break;
        while(K>=cost[i]){
                K -= cost[i];
                coin++;
        }
    }
    cout << coin << "\n";
    return 0;
}
