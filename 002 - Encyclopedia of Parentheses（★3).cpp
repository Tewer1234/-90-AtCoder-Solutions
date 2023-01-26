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
char path[SIZE];
void dfs(int cur,int l,int r,int n){
  //cur is the current position in the string we will be working with right now
  //l is the amount of '(' we have in our string currently
  //r is the amount of ')' we have in our string currently
  //n is the final length we want for our string
  
  //if we are able to make a string that has a length of n, then we will output it
  if (cur==n){
    cout<<path<<"\n";
    return;
  }else{
    //since a string will contain half '(' and half ')', we will set a condition
    //to limit the formation of our string
    if ((l+1)<=n/2){
      path[cur]='(';
      dfs(cur+1,l+1,r,n);
    }
    
    //also, we will only put ')' when there are '(' infront of it.
    if ((r+1)<=l){
      path[cur]=')';
      dfs(cur+1,l,r+1,n);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s="";
  cin>>n;
  path[0]='(';
  //if n is odd, then we should output nothing
  if ((n%2)) cout<<s;
  else{
    dfs(1,1,0,n);
  }
  return 0; 
}
