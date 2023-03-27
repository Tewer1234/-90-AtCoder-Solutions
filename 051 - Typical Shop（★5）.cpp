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
#include <vector>
#define ll long long int
#define SIZE 400005
#define pb push_back
#define ll long long int
using namespace std;
ll ary[SIZE];
ll bry[SIZE];
vector <ll> asum[50];
vector <ll> bsum[50];
int main() {
  int N,K;
  ll P;
  cin>>N>>K>>P;
  for (int i=0;i<N/2;i++) cin>>ary[i];
  for (int i=N/2;i<N;i++) cin>>bry[i-(N/2)];
  
  ll tsum=0;
  int temp,l,r,mid;
  
  for (int i=1;i<(1<<(N/2));i++){
    tsum=0;
    temp=0;
    for (int j=0;j<N/2;j++){
      if ((1<<j)&i){
        temp++;
        tsum+=ary[j];
      }
    }
    asum[temp].pb(tsum);
  }
  
  int len=N-(N/2);
  for (int i=1;i<(1<<len);i++){
    tsum=temp=0;
    for (int j=0;j<len;j++){
      if ((1<<j)&i){
        temp++;
        tsum+=bry[j];
      }
    }
    bsum[temp].pb(tsum);
  }
  
  for (int i=1;i<=N;i++) sort(bsum[i].begin(),bsum[i].end());
  
  ll ans=0;
  for (int i=1;i<=K;i++){
    for (int j=0;j<asum[i].size();j++){
      int pos=-1;
      len=K-i;
      l=0,r=bsum[len].size()-1;
      
      while (l<=r){
        mid=(l+r)/2;
        if (bsum[len][mid]+asum[i][j]<=P){
          pos=mid;
          l=mid+1;
        }else r=mid-1;
      }
      
      if (pos!=-1){
        ans+=(pos+1);
      }
    }
  }
  
  for (int i=0;i<asum[K].size();i++){
    if (asum[K][i]<=P) ans++;
  }
  for (int i=0;i<bsum[K].size();i++){
    if (bsum[K][i]<=P) ans++;
  }
  cout<<ans;
  
  return 0;
}
