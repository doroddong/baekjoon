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
#define MAX 64
#define INF 987654321
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int map[MAX][MAX];




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i=0;i<n;i++){
        string map_str;
        cin >> map_str;

        for(int j=0;j<map_str.size();j++){
            map[i][j] = map_str[j] - '0';
        }
    }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << map[i][j];
    //     }
    //     cout<<endl;
    // }


    
    return 0;
}

