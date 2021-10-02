//
//  main.cpp
//  17281_야구공
//
//  Created by 이동훈 on 2020/09/08.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

#define inRange(x,y,max_x,max_y) ((0<=x) && (x<max_x) && (0<=y) && (y<max_y))
#define swap(a,b) {int t = a; a=b; b=t;}
#define MAX 100001
#define INF 987654321
#define endl "\n"

using namespace std;

int N, ans;
int info[50][9]; // 각 이닝별 타자 정보
int order[9]; // 타자 순번
bool selected[9];
void Game() {
    int idx = 0, score = 0; // 순번 인덱스, 현재 점수
    for(int inning = 0; inning < N; ++inning) {
        bool is_there[3] = { false, false, false }; // 1, 2, 3루
        int out = 0;
        while (true) {
            if (info[inning][order[idx]] == 0) { // 아웃
                out++;
            }
            else if (info[inning][order[idx]] == 1) { // 1루타
                if (is_there[2]) { // 3루타 -> 홈
                    score++; is_there[2] = false;
                }
                for (int i = 1; i != -1; --i) { // 각각 1 전진
                    if (is_there[i]) {
                        is_there[i + 1] = true;
                        is_there[i] = false;
                    }
                }
                is_there[0] = true; // 1루 전진
            }
            else if (info[inning][order[idx]] == 2) { // 2루타
                for (int i = 1; i < 3; ++i) { // 2루, 3루 -> 홈
                    if (is_there[i]) {
                        score++; is_there[i] = false;
                    }
                }
                if (is_there[0]) { // 1루 -> 3루
                    is_there[2] = true; is_there[0] = false;
                }
                is_there[1] = true; // 2루 전진
            }
            else if (info[inning][order[idx]] == 3) { // 3루타
                for (int i = 0; i < 3; ++i) { // 1, 2, 3루 -> 홈
                    if (is_there[i]) {
                        score++; is_there[i] = false;
                    }
                }
                is_there[2] = true; // 3루 전진
            }
            else { // 홈런
                for (int i = 0; i < 3; ++i) {
                    if (is_there[i]) {
                        score++; is_there[i] = false;
                    }
                }
                score++;
            }
            idx = (idx + 1) % 9; // 다음 순번
            if (out == 3) break; // 3진 아웃
        }
    }
    if (ans < score) ans = score;
}
void SelectOrder(int cnt) {
    if (cnt == 9) {
        Game();
        return;
    }
    if (cnt == 3) cnt++;
    for (int i = 1; i < 9; ++i) {
        if (selected[i]) continue;
        selected[i] = true;
        order[cnt] = i;
        SelectOrder(cnt + 1);
        selected[i] = false;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> info[i][j];
        }
    }
    selected[0] = true; order[3] = 0; // 1번 선수 4번째 고정
    SelectOrder(0);
    cout << ans << "\n";
    return 0;
}
