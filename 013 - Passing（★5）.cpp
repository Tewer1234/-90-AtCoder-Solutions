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
vector <int> nodes[SIZE];
vector <int> w[SIZE];
int dis1[SIZE];
int dis2[SIZE];
void dijk(int st,int n,int (&dis) [SIZE]){
  priority_queue <pp,vector<pp>,greater<pp> > pq;
  for (int i=1;i<=n;i++) dis[i]=INT_MAX;
  dis[st]=0;
  pq.push(make_pair(dis[st],st));
  
  while (!pq.empty()){
    int cur=pq.top().second;
    pq.pop();
    for (int i=0;i<w[cur].size();i++){
      int nxt=nodes[cur][i];
      if (dis[nxt]>dis[cur]+w[cur][i]){
        dis[nxt]=dis[cur]+w[cur][i];
        pq.push(make_pair(dis[nxt],nxt));
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,x,y,s;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y>>s;
    nodes[x].pb(y);
    nodes[y].pb(x);
    w[x].pb(s);
    w[y].pb(s);
  }
  
  dijk(1,n,dis1);
  dijk(n,n,dis2);
  for (int i=1;i<=n;i++){
    cout<<dis1[i]+dis2[i]<<"\n";
  }
  return 0; 
}
