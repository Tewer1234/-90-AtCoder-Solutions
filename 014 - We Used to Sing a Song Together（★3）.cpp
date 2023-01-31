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
int ary[SIZE],bry[SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int j=1;j<=n;j++) cin>>bry[j];
  
  sort(ary+1,ary+n+1);
  sort(bry+1,bry+n+1);
  ll ans=0;
  for (int i=1;i<=n;i++){
    ans+=abs(ary[i]-bry[i]);
  }
  cout<<ans;
  return 0; 
}
