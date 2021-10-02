//
//  main.cpp
//  2503_야구게임.cpp
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int n, question, strike, ball,possible;
bool arr[1000];
string one, two;

void initializeArr() {
    for (int i = 123; i < 1000; i++) {
        string temp = to_string(i);
        if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
            arr[i] = false;
        if (temp[0] - '0' == 0 || temp[1] - '0' == 0 || temp[2] - '0' == 0)
            arr[i] = false;
    }
}

int main() {

    cin >> n;
    
    memset(arr, true, sizeof(arr));
    initializeArr();

    for (int k = 0; k < n; k++) {
        cin >> question >> strike >> ball;
        for (int i = 123; i < 1000; i++) {
            int strike_count = 0;
            int ball_count = 0;

            if (arr[i]) {
                one = to_string(question);
                two = to_string(i);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (x == y &&one[x] == two[y])
                            strike_count++;
                        if (x != y &&one[x] == two[y])
                            ball_count++;
                    }
                }
                if (strike_count != strike || ball_count != ball)
                    arr[i] = false;
            }
        }
    }
    
    for (int i = 123; i < 1000; i++) {
        if (arr[i] == true)
            possible++;
    }

    cout << possible << "\n";
    return 0;
}
