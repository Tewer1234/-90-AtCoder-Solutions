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
char grid[1005][1005];
int dist[1005][1005][5];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
struct node{
  int x,y,dir;
};
deque <node> dq;
int ans;
void bfs(int r,int c,int sx,int sy,int ex,int ey){
  node cur,nxt,temp;
  temp.x=sx;
  temp.y=sy;
  for (int i=0;i<4;i++){
    temp.dir=i;
    dq.pb(temp);
    dist[sx][sy][i]=0;
  }
  while (!dq.empty()){
    cur=dq.front();
    dq.pop_front();
    for (int k=0;k<4;k++){
      nxt=cur;
      nxt.x+=moves[k][0],nxt.y+=moves[k][1];
      if ((nxt.x>=1 and nxt.x<=r) and (nxt.y>=1 and nxt.y<=c) and grid[nxt.x][nxt.y]!='#'){
        int cost=dist[cur.x][cur.y][cur.dir];
        if (k!=cur.dir) cost++;
        if (cost<dist[nxt.x][nxt.y][k]){
          dist[nxt.x][nxt.y][k]=cost;
        
          nxt.dir=k;
          if (k!=cur.dir) dq.pb(nxt);
          else dq.push_front(nxt);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r,c,sx,sy,ex,ey;
  cin>>r>>c>>sx>>sy>>ex>>ey;
  for (int i=1;i<=r;i++){
    for (int j=1;j<=c;j++){
      cin>>grid[i][j];
    }
  }

  memset(dist,inf,sizeof(dist));
  ans=INT_MAX;
  // dist[sx][sy][0]=0;
  // for (int i=0;i<=4;i++) dist[sx][sy][i]=0;
  bfs(r,c,sx,sy,ex,ey);

  for (int i=0;i<4;i++) ans=min(ans,dist[ex][ey][i]);
  cout<<ans;
  return 0;
}
