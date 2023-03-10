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
bool check(int n,int k,ll num,ll r){
  //le stands for the left bound
  //cnt will record the amount of cuts already made
  ll le=0;
  int cnt=0;
  for (int i=1;i<=n;i++){
    if (cnt==k) break;
    //if the difference between the first half or the second half is less than the minimum difference allowed (num), then no cut will be performed on this current segment. 
    if (ary[i]-le>=num and r-ary[i]>=num){
      cnt++;
      le=ary[i];
    }
  }
  
  if (cnt<k or cnt>k) return false;
  else return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  ll L;
  cin>>n>>L>>k;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  ll l,r,mid,temp=0;
  l=1;
  r=L;
  //Binary Search for the minimum length difference between each cut segment
  while (l<=r){
    mid=(l+r)/2;
    if (check(n,k,mid,L)){
      temp=mid;
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  cout<<temp;
  return 0; 
}
