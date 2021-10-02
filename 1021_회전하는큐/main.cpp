//
//  main.cpp
//  1021_회전하는큐
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

deque<int> deq;

int main() {

    int N, M, input, index, count, left, right;
    deque<int>::iterator it;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }

    count = 0;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (deq.front() == input) {
            deq.pop_front();
        }
        else {
            index = 1;

            for (it = deq.begin(); it < deq.end(); it++) {
                if (*it == input) {
                    break;
                }
                index++;
            }
            left = index - 1;
            right = deq.size() - index + 1;

            if (left >= right) {
                for (int j = 0; j < right; j++) {
                    deq.push_front(deq.back());
                    deq.pop_back();
                }
                count += right;
                deq.pop_front();
            }

            else if (left <= right) {
                for (int j = 0; j < left; j++) {
                    deq.push_back(deq.front());
                    deq.pop_front();
                }
                count += left;
                deq.pop_front();
            }
        }
    }
    cout << count << endl;

    return 0;

}
