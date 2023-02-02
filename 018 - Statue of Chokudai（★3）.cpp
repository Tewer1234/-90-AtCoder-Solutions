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
#define pi 3.14159265358979323846
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,T,l,q;
  double x,y,x1,y1,z1;
  cin>>T>>l>>x>>y>>q;
  for (int i=1;i<=q;i++){
    cin>>n;
    n%=T;
    if (!n) cout<<fixed<<setprecision(7)<<0<<"\n";
    else{
      x1=0.0;
      y1=((double) -l/2)*sin(2.0*(double)pi*((double) n/T));
      z1=((double) l/2)+((double) -l/2)*cos(2.0*(double)pi*((double) n/T));
      
      // cout<<x1<<" "<<y1<<" "<<z1<<"\n";
      // cout<<x<<" "<<y<<" "<<0<<"\n";
      double opp=z1;
      double adj=sqrt((x*x)+(y1-y)*(y1-y));
      
      cout<<fixed<<setprecision(7)<<atan(opp/adj)*(180.0/pi)<<"\n";
    }
  }
  return 0; 
}
