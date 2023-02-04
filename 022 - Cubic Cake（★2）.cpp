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
unsigned ll gcd(unsigned ll a,unsigned ll b){
  unsigned ll t;
  while (b!=0){
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned ll a,b,c;
  cin>>a>>b>>c;
  
  unsigned ll GCD=min({gcd(a,b),gcd(a,c),gcd(b,c)});
  a/=GCD,b/=GCD,c/=GCD;
  cout<<(a-1)+(b-1)+(c-1);
  
  return 0; 
}
