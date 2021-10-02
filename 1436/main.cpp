//
//  main.cpp
//  1436
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1000001;

int dp[MAX];

int make_one(int number)
{
    if (number == 1)
        return 0;
    if (dp[number] != -1)
        return dp[number];

    int result = make_one(number - 1) + 1;
    if (number % 3 == 0)
        result = min(result, make_one(number / 3) + 1);
    if (number % 2 == 0)
        result = min(result, make_one(number / 2) + 1);
    dp[number] = result;
    return result;
}

int main()
{
    int n;
    cin >> n;
    fill(dp,dp+MAX,-1);
    cout << make_one(n) << endl;

    return 0;
}
