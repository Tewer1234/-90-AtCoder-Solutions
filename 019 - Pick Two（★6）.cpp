#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[SIZE];
int dp[405][405];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=2*n;i++) cin>>ary[i];
  
  memset(dp,inf,sizeof(dp));
  for (int i=1;i<2*n;i++){
    dp[i][i+1]=abs(ary[i+1]-ary[i]);
  }
  
  for (int i=1;i<=2*n;i++){
    for (int j=1;j<=2*n-i;j++){
      int l=j,r=i+j;
      for (int k=l;k<r;k++){
        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
      }
      dp[l][r]=min(dp[l][r],dp[l+1][r-1]+abs(ary[l]-ary[r]));
    }
  }
  
  cout<<dp[1][2*n];
  return 0; 
}
