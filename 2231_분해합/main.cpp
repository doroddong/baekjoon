//
//  main.cpp
//  2231_분해합
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
int main() {
    long n;
    cin >> n;
    long m = n;
    int digit = 0;
    bool find = false;

    while (m) {
        m /= 10;
        digit++;
    }
    long begin = n - digit * 9;
    char str[10];
    long sum = 0;
    
    for (long i = begin; i <= n; i++) {
        sprintf(str, "%ld", i);
        sum = i;
        for (int j = 0; j < strlen(str); j++)
            sum += str[j] - '0';
        if (sum == n) {
            cout << i << '\n';
            find = true;
            break;
        }
    }
    if (find == false)
        cout << "0\n";
    return 0;
}
