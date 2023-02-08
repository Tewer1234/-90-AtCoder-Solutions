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
set <string> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>s;
    auto it=st.find(s);
    if (it==st.end()){
      cout<<i<<"\n";
      st.insert(s);
    }
  }
  return 0; 
}
