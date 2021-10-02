//
//  main.cpp
//  1158_조세퍼스 문제
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {

    int N, K;
    queue<int> q;
    
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        q.push(i);

    cout << "<";
    
    while (q.size()) {
        if (q.size() == 1) {
            cout << q.front()<< ">";
            q.pop();
            break;
        }
        else {
            for (int i = 1; i < K; i++) {
                q.push(q.front());
                q.pop();
            }
            cout << q.front() << ", ";
            q.pop();
        }
    }
    cout << "\n";
    return 0;
}
