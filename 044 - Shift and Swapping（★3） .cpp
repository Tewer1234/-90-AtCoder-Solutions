#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <deque>
#define ll long long int
#define SIZE 400005
#define pb push_back
#define inf 0x3f3f3f3f
#define dd 1e9+7
using namespace std;
typedef pair<int,int> pp;
int ary[SIZE];
int qq[4*SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q,t,x,y;
  cin>>n>>q;
  for (int i=0;i<n;i++) cin>>ary[i];
  
  int front=0,back=n-1;
  for (int i=n-1,j=0;i>=0 and j<n;i--,j++) qq[j]=i;
  
  for (int i=1;i<=q;i++){
    cin>>t>>x>>y;
    if (t==1){
      int pos1=back-x+1;
      int pos2=back-y+1;
      swap(qq[pos1],qq[pos2]);
    }else if (t==2){
      int temp=qq[front];
      front++;
      back++;
      qq[back]=temp;
    }else{
      int pos=back-x+1;
      // cout<<back<<" "<<pos<<" "<<qq[pos]<<"\n";
      cout<<ary[qq[pos]]<<'\n';
    }
    // cout<<front<<' '<<back<<": ";
    // for (int j=front;j<=back;j++){
    //   cout<<qq[j]<<" ";
    // }
    // cout<<"\n";
  }
  return 0;
}
