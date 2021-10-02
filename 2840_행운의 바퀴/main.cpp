//
//  main.cpp
//  2840_행운의 바퀴
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N,K;

    cin >> N >> K;

    vector<char> v(N);
    fill(v.begin(), v.end(), '?');
    
    int idx = 0;
    for (int i = 0; i < K; i++) {
        int S;
        char c;

        cin >> S >> c;

        S %= N;
        
        if (idx - S < 0)
            idx = (idx - S) + N;
        else
            idx -= S;

        if (v[idx] != '?'&&v[idx] != c) {
            cout << "!\n";
            return 0;
        }
        else
            v[idx] = c;
    }

    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            if (v[i] != '?'&&v[i] == v[j]) {
                cout << "!\n";
                return 0;
            }

    for (int i = 0; i < N; i++)
        cout << v[(i+idx)%N];
    cout << "\n";
    return 0;


    return 0;
}
