#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,row,col;
  cin>>n>>row>>col;
  int **m=new int*[n];
  for(int i=0;i<n;i++){
    m[i]=new int[n];
    for(int j=0;j<n;j++){
      m[i][j]=0;
    }
  }
  m[row][col]=1;
printKnightTour(n,row,col,m[row][col]);   
}
