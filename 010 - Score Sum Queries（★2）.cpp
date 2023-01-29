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
#define rem 1e9+7
using namespace std;
typedef pair<int,int> pp;
int ary[5][SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,c,p;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>c>>p;
    ary[1][i]+=ary[1][i-1];
    ary[2][i]+=ary[2][i-1];
    ary[c][i]+=p;
  }
  
  int q,l,r;
  cin>>q;
  for (int i=1;i<=q;i++){
    cin>>l>>r;
    int class1=ary[1][r]-ary[1][l-1];
    int class2=ary[2][r]-ary[2][l-1];
    cout<<class1<<" "<<class2<<"\n";
  }
  
  
  return 0; 
}
