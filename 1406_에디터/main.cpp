//
//  main.cpp
//  1406_에디터
//
//  Created by 이동훈 on 2021/10/02.
//  Copyright © 2021 이동훈. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){

    int n;
    string str;

    cin >> str;
    cin >> n;

    list<char> editor(str.begin(), str.end());
    
    list<char>::iterator cursor = editor.end();

    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cursor != editor.begin())
                cursor--;
        }
        else if (cmd == 'D') {
            if (cursor != editor.end()) {
                cursor++;
            }
        }
        else if (cmd == 'B') {
            if (cursor != editor.begin()) {
                cursor--;
                cursor=editor.erase(cursor);
            }
        }
        else if (cmd == 'P') {
            char input;
            cin >> input;
            editor.insert(cursor, input);
        }
    }
    
    for (list<char>::iterator iter = editor.begin(); iter != editor.end(); iter++) {
        cout << *iter;
    }
    cout << endl;
    return 0;
}
