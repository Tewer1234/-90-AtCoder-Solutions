#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#define inf 0x3f3f3f3f
#define ll long long int 
#define SIZE 400005
using namespace std;
typedef pair <int,int> pp;
int ary[1005][1005];
int cant[1005][1005];
int pick[SIZE];
int used[SIZE];
int tt[SIZE];
int ans;
void dfs(int pos,int n){
  if (pos>n){
    int temp=0,check=1;
    for (int i=1;i<n;i++){
      if (cant[tt[i]][tt[i+1]]){
        check=0;
        break;
      }
    }
    
    if (check){
      for (int i=1;i<=n;i++){
        temp+=ary[i][pick[i]];
      }
      ans=min(ans,temp);
    }
    return;
  }else{
    for (int i=1;i<=n;i++){
      if (!used[i]){
        used[i]=1;
        pick[pos]=i;
        tt[i]=pos;
        dfs(pos+1,n);
        used[i]=0;
      }
    }
  }
}
int main() {
  int n,m,x,y;
  cin>>n;
  
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      cin>>ary[i][j];
    }
  }

  cin>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y;
    cant[x][y]=1;
    cant[y][x]=1;
  }
  
  ans=INT_MAX;
  dfs(1,n);
  if (ans==INT_MAX) cout<<-1;
  else cout<<ans;
  return 0;
}
