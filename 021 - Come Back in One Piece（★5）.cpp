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
int id,scc;
int ids[SIZE];
int onStack[SIZE];
int low[SIZE];
int cc[SIZE];
stack <int> st;

void dfs(int n){
  id++;
  ids[n]=low[n]=id;
  onStack[n]=1;
  st.push(n);
  
  for (int i=0;i<nodes[n].size();i++){
    int nxt=nodes[n][i];
    if (!ids[nxt]) dfs(nxt);
    if (onStack[nxt]) low[n]=min(low[n],low[nxt]);
  }
  
  if (ids[n]==low[n]){
    while (!st.empty()){
      int t=st.top();
      low[t]=low[n];
      onStack[t]=0;
      st.pop();
      if (t==n) break;
    }
    // scc++;
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,x,y;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y;
    nodes[x].pb(y);
  }

  
  for (int i=1;i<=n;i++){
    if (!ids[i]){
      dfs(i);
    }  
  }
  
  for (int i=1;i<=n;i++) cc[low[i]]++;
  
  ll ans=0;
  for (int i=1;i<=n;i++){
    ans+=((ll) cc[i]*(cc[i]-1)/2);
  }
  cout<<ans;
  return 0; 
}
