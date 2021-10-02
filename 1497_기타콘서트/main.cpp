//
//  main.cpp
//  1497_기타콘서트
//
//  Created by 이동훈 on 2020/08/24.
//  Copyright © 2020 이동훈. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int max_music = 0, min_guitar = 11;
int n,m;
long long guitar[11];
bool flag = false;

int count_bit(long long bit){
  int result = 0;
  while(bit){
    //1의 자리가 1인지 계산
    result +=bit&1;
    // 오른쪽으로 shift
    bit >>= 1;
  }
  return result;
}
bool dfs(int index, int count, long long bit){
  int music_count = count_bit(bit);

  // 우선순위 : 최대한 많은 곡을 연주
  //최대 곡인 경우
  if(max_music<music_count){
    max_music = music_count;
    min_guitar = count;
  }
  //동일한 곡의 개수인 경우 최소값 갱신
  else if (max_music==music_count) min_guitar=min(min_guitar,count);

  if(index >= n)  return;

  //index인 기타 선택
    // index 기타를 선택하면, bit는 or 연산
  dfs(index+1,count+1,bit | guitar[index]);
  //index인 기타 선택 X
  dfs(index+1,count,bit);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(guitar,0,sizeof(guitar));
  cin >> n >> m;


  for(int i=0;i<n;i++){
    string name, possible;
    cin >> name >> possible;
    
    for(int j=0;j<m;j++){
        
        // possible[j] == Y라면
        // m-j-1만큼 왼쪽으로 shift 하여 or 연산
        
        // YYYNN이었다면 guitar 에는 11100으로 변환
        if(possible[j]=='Y'){
            guitar[i]|=(1LL<<(m-j-1));
        }
    }
  }

  dfs(0,0,0);

  if(max_music==0)  cout<<-1;
  else cout<<min_guitar;

  return 0;
}
