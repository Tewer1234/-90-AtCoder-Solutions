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
int ary[2005][2005];
int hsum[SIZE];
int wsum[SIZE];
int sum[2005][2005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h,w;
  cin>>h>>w;
  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      cin>>ary[i][j];
    }
  }
  
  //Since the sum of an entire column is the same, we add up the sum
  //of all the elements in that column and store it in the array hsum
  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      hsum[i]+=ary[i][j];
    }
  }
  
  //Since the sum of an entire row is the same, we add up the sum
  //of all the elements in that row and store it in the array wsum
  for (int i=1;i<=w;i++){
    for (int j=1;j<=h;j++){
      wsum[i]+=ary[j][i];
    }
  }
  
  //We need to subtract ary[i][j] because hsum[i] and wsum[j] added the element ary[i][j] twice
  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      sum[i][j]=hsum[i]+wsum[j]-ary[i][j];
    }
  }
  
  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      cout<<sum[i][j]<<" ";
    }
    cout<<"\n";
  }
  
  return 0; 
}
