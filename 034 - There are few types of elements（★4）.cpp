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
map <int,int> mp;
int main() {
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  int pos=1,ans=0;
  for (int i=1;i<=n;i++){
    auto it=mp.find(ary[i]);
    mp[ary[i]]++;
    if (mp.size()>k){
      while (mp.size()>k){
        mp[ary[pos]]--;
        if (!mp[ary[pos]]){
          mp.erase(ary[pos]);
        }
        pos++;
      }
    }
    ans=max(ans,i-pos+1);
    // for (auto it:mp){
    //   cout<<it.first<<" "<<it.second<<"\n";
    // }
    // cout<<"\n";
  }
  // if (mp.size()<=k) ans=max(ans,n-pos+1);
  cout<<ans;
  return 0;
}
