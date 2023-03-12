#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <deque>
#define ll long long int
#define SIZE 400005
#define pb push_back
#define inf 0x3f3f3f3f
#define dd 1e9+7
using namespace std;
typedef pair<int,int> pp;
int ary[5][SIZE];
ll dp[5][50];
ll used[5][50];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=3;i++){
    for (int j=1;j<=n;j++){
      cin>>ary[i][j];
      ary[i][j]%=46;
    }
  }

  used[0][0]=1;
  dp[0][0]=1;

  for (int i=1;i<=3;i++){
    for (int j=1;j<=n;j++){
      for (int k=0;k<=46;k++){
        ll temp=(k+ary[i][j])%46;
        if (used[i-1][k]){
          used[i][temp]=1;
          dp[i][temp]+=dp[i-1][k];
          // cout<<temp<<"\n";
        }
      }
    }
  }
  // for (int i=1;i<=3;i++){
  //   for (int j=0;j<=46;j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  cout<<dp[3][0];
  return 0;
}
