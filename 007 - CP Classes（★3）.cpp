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
vector <int> ary;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q,num;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>num,ary.pb(num);
  
  sort(ary.begin(),ary.end());
  
  // for (int i=0;i<ary.size();i++) cout<<ary[i]<<"\n";
  // cout<<"\n";
  
  cin>>q;
  for (int i=1;i<=q;i++){
    cin>>num;
    int l=0,r=n-1,mid,temp=-1;
    auto lower=lower_bound(ary.begin(),ary.end(),num);
    int upper=ary[0];
    while (l<=r){
      mid=(l+r)/2;
      if (ary[mid]<=num){
        temp=mid;
        l=mid+1;
      }else r=mid-1;
    }
    if (temp!=-1) upper=ary[temp];
    // cout<<(*lower)<<" "<<upper<<"\n";
    cout<<min(abs((*lower)-num),abs(upper-num))<<"\n";
  }
return 0; 
}
