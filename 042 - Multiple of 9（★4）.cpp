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
  int n;
  cin>>n;
  
  ary[0]=1;
  if (n%9!=0) cout<<0;
  else{
    for (int i=0;i<=n;i++){
      for (int j=1;j<=9;j++){
        ary[i+j]=(ary[i+j]%((ll)dd)+ary[i]%((ll)dd))%((ll)dd);
      }
    }
    cout<<ary[n]%((ll)dd);
  }
  return 0;
}
