//
//  main.cpp
//  3085_사탕게임
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

#define MAX 50

using namespace std;

int board_size;

string board[MAX];

int maximize_Candy() {
    int result = 1;

    for (int i = 0; i < board_size; i++) {
        int temp = 1;
        for (int j = 1; j < board_size; j++) {
            if (board[i][j - 1] == board[i][j])
                temp++;
            else {
                result = max(result, temp);
                temp = 1;
            }
        }
        result = max(result, temp);
    }

    for (int i = 0; i < board_size; i++) {
        int temp = 1;
        for (int j = 0; j < board_size-1; j++) {
            if (board[j + 1][i] == board[j][i])
                temp++;
            else {
                result = max(result, temp);
                temp = 1;
            }
        }
        result = max(result, temp);
    }
    return result;
}

int main() {
    cin >> board_size;
    
    for (int i = 0; i < board_size; i++) {
        cin >> board[i];
    }

    int candy_max = 0;
    
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size - 1; j++) {
            swap(board[i][j], board[i][j+1]);
            candy_max = max(candy_max, maximize_Candy());
            swap(board[i][j], board[i][j + 1]);

            swap(board[j][i], board[j + 1][i]);
            candy_max = max(candy_max, maximize_Candy());
            swap(board[j][i], board[j + 1][i]);
        }
    }
    cout << candy_max << "\n";
    return 0;
}
