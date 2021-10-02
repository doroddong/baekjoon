//
//  main.cpp
//  10448_유레카 이론
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

#define MAX 45

using namespace std;
int T_num[MAX];

bool isTriangle_num(int n) {
    int temp = 0;
    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++)
            for (int k = 1; k < MAX; k++) {
                temp = T_num[i] + T_num[j] + T_num[k];
                if (temp == n) {
                    return true;
                }
            }
    return false;
}

int main() {

    //1000 ������ �ﰢ�� ���ϱ� T(n)
    for (int i = 1; i < 45; i++) {
        int T_n = 0;
        T_n = i*(i + 1) / 2;
        if (T_n < 1000) {
            T_num[i] = T_n;
        }
        else
            break;
    }
    int TestCase;
    cin >> TestCase;
    
    for (int i = 0; i < TestCase; i++) {
        int n, result;
        cin >> n;
        result=isTriangle_num(n);

        if (result == true) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
        
    }
    
    return 0;
}
