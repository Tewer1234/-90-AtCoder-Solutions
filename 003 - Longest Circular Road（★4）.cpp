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
ll ary[SIZE];
int ans;
int depth[SIZE],used[SIZE];
vector <int> nodes[SIZE];

//First find the distance to each node from the assumed root, 1
//Then, we will set the variable called, "node" (deepest node) to be the root of our new DFS traversal
//Finally, we take the longest distance from "node" and output the answer. Remember to add 1 because it is asking for a circular path
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
  
  used[1]=1;
  dfs(1);
  
  // for (int i=1;i<=n;i++){
  //   cout<<i<<": "<<depth[i]<<"\n";
  // }
  
  int c=0,node=1;
  for (int i=1;i<=n;i++){
    if (depth[i]>c){
      c=depth[i];
      node=i;
    }
  }
  
  memset(used,0,sizeof(used));
  memset(depth,0,sizeof(depth));
  used[node]=1;
  // ans+=depth[node];
  dfs(node);
  for (int i=1;i<=n;i++){
    ans=max(ans,depth[i]);
  }
  
  cout<<ans+1;
  return 0; 
}
