//
//  main.cpp
//  2346_풍선 터뜨리기
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

struct Balloons {
    int index;
    int value;
};
deque<Balloons> deq;

void printque() {
    for (int i = 0; i < deq.size(); i++) {
        cout << deq.front().value;
    }
}
int main() {

    int n, move;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        Balloons init;
        init.index = i;
        init.value = a;
        deq.push_back(init);
    }

    while (deq.size() > 0) {
        move = deq.front().value;
        cout << deq.front().index << " ";
        deq.pop_front();

        if (deq.size() == 1) {
            cout << deq.front().index<<" ";
            break;
        }
        else if (move > 0) {
            for (int i = 0; i < move - 1; i++) {
                deq.push_back(deq.front());
                deq.pop_front();
            }

        }
        else {
            for (int i = move; i < 0; i++) {
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    
    return 0;
}
