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
ll ary[SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,l;
  cin>>n>>l;
  
  ary[0]=1;
  for (int i=0;i<=n;i++){
    if (ary[i]){
      ary[i+1]=(ary[i+1]+ary[i])%((ll)dd);
      ary[i+l]=(ary[i+l]+ary[i])%((ll)dd);
    }
  }
  
  cout<<ary[n];
  

  return 0;
}
