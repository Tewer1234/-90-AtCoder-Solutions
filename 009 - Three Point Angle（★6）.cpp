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
ll x[SIZE],y[SIZE];
vector <double> angle;
double getAngleAB(ll ax,ll ay){
  //Point A is above point B. Thus, giving us a counterclockwise (+) angle
  if (ay>=0.0){
    //By using the definition of cos, we can get the ratio of two sides
    //of the triangle. Then, we could use the inverse function to solve for ag in degrees.
    double theta=(double) ax/sqrt((ax*ax)+(ay*ay));
    double ag=acos(theta)*180.0/pi;
    return ag;
  }else{
  //Point A is below point B. Thus, giving us a clockwise (-) angle
    double theta=(double) ax/sqrt((ax*ax)+(ay*ay));
    double ag=acos(theta)*180.0/pi;
    return 360.0-ag;
  }
}

double getAngleABC(double a,double c){
  double theta=abs(a-c);
  if (theta>=180) theta=360.0-theta;
  return theta;
}

double findAngle(int b,int n){
  //Choosing Point A
  angle.clear();
  for (int i=1;i<=n;i++){
    if (i!=b){
      double ag=getAngleAB(x[i]-x[b],y[i]-y[b]);
      angle.pb(ag);
    }
  }
  sort(angle.begin(),angle.end());

  //Choosing Point C
  double tempans=0.0;
  for (int i=0;i<angle.size();i++){
    double ri=angle[i]+180.0;
    if (ri>=360) ri-=360.0;
    int c=lower_bound(angle.begin(),angle.end(),ri)-angle.begin();
    
    //There are only two options for the possible angle of ABC
    int c1=c%angle.size();
    int c2=(c+angle.size()-1)%angle.size();
    
    double finalAngle1=getAngleABC(angle[i],angle[c1]);
    double finalAngle2=getAngleABC(angle[i],angle[c2]);
    // cout<<finalAngle1<<" "<<finalAngle2<<" "<<tempans<<"\n";
    tempans=max({finalAngle1,finalAngle2,tempans});
    
  }
  return tempans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>x[i]>>y[i];
  }
  
  //Choosing Point B
  double ans=0.0;
  for (int i=1;i<=n;i++){
    double temp=findAngle(i,n); 
    ans=max(ans,temp);
  }
  cout<<fixed<<setprecision(7)<<ans;
  return 0; 
}
