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
int bry[SIZE];
vector <int> dif;
bool comp(int a,int b){
  return a>b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>ary[i]>>bry[i];
  
  for (int i=1;i<=n;i++){
    dif.pb(ary[i]-bry[i]);
    dif.pb(bry[i]);
  }
  
  sort(dif.begin(),dif.end(),comp);
  
  ll ans=0;
  for (int i=0,j=1;i<dif.size() and j<=k;i++,j++){
    ans+=dif[i];
  }
  
  cout<<ans;
  
  return 0;
}
