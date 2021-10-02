//
//  main.cpp
//  1931_회의실배정
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time {
    int begin;
    int end;
};

bool cmp(Time t, Time i) {
    if (t.end == i.end)
        return t.begin < i.begin;
    else
        return t.end < i.end;
}
int main() {
    
    int N;
    cin >> N;

    vector<Time> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i].begin >> t[i].end;
    }

    sort(t.begin(), t.end(), cmp);

    int cnt = 0;
    int end = 0;

    for (int i = 0; i < t.size(); i++) {
        if (end <= t[i].begin) {
            end = t[i].end;
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
