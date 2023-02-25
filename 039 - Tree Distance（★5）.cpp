#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#define SIZE 400005
#define pb push_back
#define ll long long int
using namespace std;
typedef pair<int,int> pp;
int ary[SIZE];
ll dp[SIZE];
vector <int> nodes[SIZE];
int used[SIZE];
ll ans;
void dfs(int n,int N){
  int nxt;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (!used[nxt]){
      used[nxt]=1;
      dfs(nxt,N);
      dp[n]+=dp[nxt];
    }
  }
  
  ans+=(dp[n]*(N-dp[n]));
}
int main() {
  int n,x,y;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>x>>y;
    nodes[x].pb(y);
    nodes[y].pb(x);
  }
  
  for (int i=1;i<=n;i++) dp[i]=1;
  
  used[1]=1;
  dfs(1,n);
  cout<<ans;
  return 0;
}
