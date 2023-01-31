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
vector <ll> t;
struct node{
  int d,c,s;
};
node ary[SIZE];
int cur[SIZE];
ll dp[5005];
bool comp(node a,node b){
  if (a.d<b.d) return true;
  else if (a.d==b.d and a.c<b.c) return true;
  else return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,days=0;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i].d>>ary[i].c>>ary[i].s,days=max(days,ary[i].d);
  
  sort(ary+1,ary+n+1,comp);
  
  for (int i=1;i<=n;i++){
    t.clear();
    for (int j=1;j<=days;j++){
      int pos=j-ary[i].c+1;
      if (j<=ary[i].d and pos>=1){
        pos--;
        t.pb(max(dp[j],dp[pos]+ary[i].s));
      }else t.pb(dp[j]);
    }
    
    // for (int j=1;j<=days;j++) cout<<"DAY "<<j<<": "<<t[j-1]<<"\n";
    // cout<<"\n";
    
    for (int j=1;j<=days;j++) dp[j]=t[j-1];
  }
  
  ll ans=0;
  for (int i=1;i<=days;i++) ans=max(ans,dp[i]);
  cout<<ans;
  return 0; 
}
