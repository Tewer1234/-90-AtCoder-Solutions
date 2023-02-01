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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=3;i++) cin>>ary[i];
  
  int ans=INT_MAX;
  int limit=9999;
  for (int i=0;i<=limit;i++){
    for (int j=0;i+j<=limit;j++){
      int z=(n-ary[1]*i-ary[2]*j)/ary[3];
      if (z<=limit and z>=0 and ary[1]*i+ary[2]*j+ary[3]*z==n){
        ans=min(ans,i+j+z);
      }
    }
  }
  cout<<ans;
  
  return 0; 
}
