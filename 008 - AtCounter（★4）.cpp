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
#define rem 1e9+7
using namespace std;
typedef pair<int,int> pp;
int ary[SIZE][200];
ll dp[200][SIZE];
string tar=" atcoder";
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin>>n>>s;
  
  s=" "+s;
  
  unsigned ll tempans,ans=0;
  for (int i=1;i<s.size();i++){
    dp[1][i]+=dp[1][i-1];
    if (s[i]=='a') dp[1][i]++;
  }
  for (int i=2;i<tar.size();i++){
    for (int j=1;j<s.size();j++){
      if (tar[i]!=s[j]) dp[i][j]=dp[i][j-1];
      else dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%((ll) rem);
    }
  }
  
  // for (int i=1;i<tar.size();i++){
  //   for (int j=1;j<s.size();j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  cout<<dp[tar.size()-1][s.size()-1];
  return 0; 
}
