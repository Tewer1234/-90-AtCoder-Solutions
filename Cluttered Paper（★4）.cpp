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
int ary[SIZE];
int grid[1005][1005];
vector <int> tt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,lx,ly,rx,ry;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>lx>>ly>>rx>>ry;
    grid[lx][ly]++;
    grid[rx][ry]++;
    grid[lx][ry]--;
    grid[rx][ly]--;
  }
  
  for (int i=0;i<=1000;i++){
    for (int j=1;j<=1000;j++){
      grid[i][j]+=grid[i][j-1];
    }
  }
  
  for (int i=1;i<=1000;i++){
    for (int j=0;j<=1000;j++){
      grid[i][j]+=grid[i-1][j];
    }
  }
  
  for (int i=0;i<=1000;i++){
    for (int j=0;j<=1000;j++){
      if (grid[i][j]>=1) ary[grid[i][j]]++;
    }
  }
  
  for (int i=1;i<=n;i++){
    cout<<ary[i]<<"\n";
  }
  
  return 0; 
}
