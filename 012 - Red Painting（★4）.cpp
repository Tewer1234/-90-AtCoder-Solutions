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
#define pi 3.14159265358979323846
using namespace std;
typedef pair<int,int> pp;
int grid[2005][2005];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
int rnk[2005][2005];
pp root[2005][2005];
pp getRoot(int x,int y){
  if (root[x][y].first==x and root[x][y].second==y){
    return make_pair(x,y);
  }else{
    return root[x][y]=getRoot(root[x][y].first,root[x][y].second);
  }
}

void merge(int x1,int y1,int x2,int y2){
  pp ra=getRoot(x1,y1);
  pp rb=getRoot(x2,y2);
  if (ra!=rb){
    if (rnk[ra.first][ra.second]<rnk[rb.first][rb.second]){
      swap(ra,rb);
    }
  
    root[ra.first][ra.second]=root[rb.first][rb.second];
    if (rnk[ra.first][ra.second]==rnk[rb.first][rb.second]){
      rnk[rb.first][rb.second]--;
    }
  }
}

bool query(int x1,int y1,int x2,int y2){
  pp ra=getRoot(x1,y1);
  pp rb=getRoot(x2,y2);
  
  if (ra!=rb) return false;
  else return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h,w,m,q,r1,r2,c1,c2;
  cin>>h>>w>>q;
  
  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      root[i][j]=make_pair(i,j);
    }
  }
  
  for (int i=1;i<=q;i++){
    cin>>m;
    if (m==1){
      cin>>r1>>c1;
      int maxRnk=-1,posx,posy,tempx,tempy;
      grid[r1][c1]=1;
      for (int j=0;j<4;j++){
        tempx=r1+moves[j][0];
        tempy=c1+moves[j][1];
        if ((tempx>=1 and tempx<=h) and (tempy>=1 and tempy<=w)){
          if (grid[tempx][tempy] and maxRnk<rnk[tempx][tempy]){
            maxRnk=rnk[tempx][tempy];
            posx=tempx;
            posy=tempy;
          }
        }
      }
      
      if (maxRnk!=-1){
        merge(posx,posy,r1,c1);
        for (int j=0;j<4;j++){
          tempx=r1+moves[j][0];
          tempy=c1+moves[j][1];
          if ((tempx>=1 and tempx<=h) and (tempy>=1 and tempy<=w)){
            merge(posx,posy,tempx,tempy);
          }
        }
      }
     
    }else{
      cin>>r1>>c1>>r2>>c2;
      if (grid[r1][c1] and grid[r2][c2]){
        if (query(r1,c1,r2,c2)) cout<<"Yes\n";
        else cout<<"No\n";
      }else{
        cout<<"No\n";
      }
    }
    
  }
  return 0; 
}
