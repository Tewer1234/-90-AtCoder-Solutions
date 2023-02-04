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
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=n;i++) cin>>bry[i];
  
  int ans=0;
  for (int i=1;i<=n;i++){
    if (ary[i]!=bry[i]){
      ans+=abs(ary[i]-bry[i]);
    }
  }
  
  int rem=k-ans;
  if (rem<0){
    cout<<"No";
  }else{
    if (!(rem%2)) cout<<"Yes";
    else cout<<"No";
  }
  return 0; 
}
