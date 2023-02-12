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
int prime[10000005];
int notPrime[10000005];
int ary[SIZE];
vector <int> tt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k,ans=0;
  cin>>n>>k;
  int li=(int)1e7;
  prime[2]=1;
  for (int i=3;i*i<=li;i+=2){
    if (!notPrime[i]){
      prime[i]=1;
      for (int j=i*i;j<=li;j+=(i+i)){
        notPrime[j]=i;
      }
    }
  }
  
  for (int i=1;i<=n;i++){
    int temp=i,p;
    tt.clear();
    while (temp>1){
      p=notPrime[temp];
      if (!(temp&1)) p=2;
      else if (!p) p=temp;
      // cout<<temp<<" "<<p<<"\n";
      tt.pb(p);
      while (temp%p==0){
        temp/=p;
      }
    }
    // cout<<i<<": "<<mp.size()<<"\n";
    if (tt.size()>=k) ans++;
  }
  
  cout<<ans;
  return 0; 
}
