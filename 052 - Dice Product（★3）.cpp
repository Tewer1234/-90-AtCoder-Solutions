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
#define inf 1e9+7
using namespace std;
typedef pair <int,int> pp;
int ary[SIZE][10];
int main() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=6;j++){
      cin>>ary[i][j];
    }
  }
  
  ll ans=1;
  for (int i=1;i<=n;i++){
    ll sum=0;
    for (int j=1;j<=6;j++){
      sum+=ary[i][j];
    }
    
    ans=(ans*sum)%((ll) inf);
  }
  cout<<ans;
  return 0;
}
