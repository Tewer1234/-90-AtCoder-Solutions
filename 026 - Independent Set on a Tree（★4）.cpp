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
vector <int> nodes[SIZE];
int used[SIZE];
int depth[SIZE];
void dfs(int n){
  int nxt;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (!used[nxt]){
      used[nxt]=1;
      depth[nxt]=depth[n]+1;
      dfs(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,x,y;
  cin>>n;
  for (int i=1;i<n;i++){
    cin>>x>>y;
    nodes[x].pb(y);
    nodes[y].pb(x);
  }
  
  dfs(1);
  int even,odd;
  even=odd=0;
  for (int i=1;i<=n;i++){
    if ((depth[i]&1)) odd++;
    else even++;
  }
  
  int cnt=0;
  if (even>=odd){
    for (int i=1;i<=n;i++){
      if (cnt==n/2) break;
      if (!(depth[i]&1)){
        cnt++;
        cout<<i<<" ";
      }
    }
  }else{
    for (int i=1;i<=n;i++){
      if (cnt==n/2) break;
      if ((depth[i]&1)){
        cnt++;
        cout<<i<<" ";
      }
    }
  }
  return 0; 
}
