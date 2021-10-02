//
//  main.cpp
//  4796_캠핑
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {

    int testcase = 1;

    while (1) {
        int L, P, V, max;
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
            break;

        max = V / P*L;

        if (V%P < L)
            max += V%P;
        else
            max += L;

        cout << "Case " << testcase << ": " << max << "\n";
        testcase++;
    }
    return 0;
}
