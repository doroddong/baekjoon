//
//  main.cpp
//  1449_수리공항승
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int main() {
    int N, L;
    int tape = 0;
    int pipe[MAX];
    bool taped[MAX];

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        cin >> pipe[i];

    sort(pipe, pipe + N);

    for (int i = 0; i < N; i++)
        if (!taped[pipe[i]]) {
            for (int j = pipe[i]; j < min(pipe[i] + L, MAX); j++)
                taped[j] = true;
            tape++;
        }
    cout << tape << "\n";
    return 0;
}
