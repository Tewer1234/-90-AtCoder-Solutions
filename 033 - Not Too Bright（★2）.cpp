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
#define inf 0x3f3f3f3f
#define ll long long int 
#define SIZE 400005
using namespace std;
typedef pair <int,int> pp;

int main() {
  int r,c;
  cin>>r>>c;
  
  int ans=0;
  if (r==1 or c==1) cout<<max(r,c);
  else{
    for (int i=1;i<=r;i+=2){
      for (int j=1;j<=c;j+=2){
        ans++;
      }
    }
    cout<<ans;
  }
  return 0;
}
