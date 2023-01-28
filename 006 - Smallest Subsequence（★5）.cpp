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
int ary[100005][200];
int cnt[200][100005];
int cur[SIZE];
int tt[200];
int tcnt[200];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  string s,t="";
  cin>>n>>k>>s;
  s=" "+s;
  for (int i=1;i<s.size();i++){
    for (char j='a';j<='z';j++){
      ary[i][j]+=ary[i-1][j];
    }
    cur[s[i]]++;
    cnt[s[i]][cur[s[i]]]=i;
    ary[i][s[i]]++;
  }
  
  int pos=0,temp=0;
  for (char i='a';i<='z';i++) tcnt[i]=1;
  for (int i=s.size()-k;i<s.size();i++){
    memset(tt,0,sizeof(tt));
    for (char j='a';j<='z';j++) tt[j]=(ary[i][j]-ary[pos][j]);
    
    // for (char j='a';j<='z';j++){
    //   cout<<j<<": "<<ary[i][j]<<" "<<ary[pos][j]<<" "<<tt[j]<<"\n";
    // }
    // cout<<"\n";
    
    for (char j='a';j<='z';j++){
      if (tt[j]>0){
        t+=j;
        while (tcnt[j]<=cur[j]){
          int check=cnt[j][tcnt[j]];
          if (check>pos){
            pos=check;
            tcnt[j]++;
            break;
          }else tcnt[j]++;
        }
        // cout<<pos<<"\n";
        break;
      }
    }
    pos=max(pos,temp);
    temp++;
  }
  
  
  cout<<t;
  return 0; 
}
