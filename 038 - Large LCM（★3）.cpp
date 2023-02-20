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
#define big 1e18
using namespace std;
typedef pair<ll,int> pp;
ll gcd(ll a,ll b){
  ll t;
  while (b!=0){
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}
int main() {
  ll a,b;
  cin>>a>>b;

  if (a==1 or b==1) cout<<a*b;
  else{
    ll t=gcd(a,b);
    ll large;
    large=a/t;
    
    if ((ll) big/large<b){
      cout<<"Large";
    }else{
      cout<<large*b;
    }
  }
  return 0;
}
