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
int ary[SIZE];
int x[SIZE],y[SIZE];
ll dist[SIZE];
ll dp[20][SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,l;
  cin>>n>>l;
  for (int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  
  int temp,first,last,cur;
  for (int i=1;i<(1<<n);i++){
    temp=i;
    ll dx,dy,dis;
    for (int j=0;j<n;j++){
      for (int k=0;k<n;k++){
        if (((temp>>j)&1)==1 and ((temp>>k)&1)==1){
          dx=x[j]-x[k];
          dy=y[j]-y[k];
          dis=dx*dx+dy*dy;
          dist[i]=max(dist[i],dis);
        }
      }
    }
  }
  
  // for (int i=1;i<(1<<n);i++) cout<<i<<": "<<dist[i]<<"\n";
  
  memset(dp,inf,sizeof(dp));
  dp[0][0]=0;
  //Set DP as dp[the current group bit j is in][the bit, "j"]
  for (int i=1;i<=l;i++){
    for (int j=1;j<(1<<n);j++){
      for (int k=j;k!=0;k=((k-1)&j)){
        dp[i][j]=min(dp[i][j],max(dp[i-1][j-k],dist[k]));
        //For example, to get 10 (decimal) = (1010), we can get from the previous
        //group's answer where the bits are:
        //2 (0010)
        //8 (1000)
        //10 (1010)
      }
    }
  }
  
  cout<<dp[l][(1<<n)-1];
  return 0;
}
