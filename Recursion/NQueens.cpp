#include<bits/stdc++.h>
using namespace std;


bool safesequence(int **m,int row,int cur ,int col){
    for(int i=cur-1;i>=0;i--){
      if(m[row][i]==1){
        return false;
      }
    }

    for(int i=row-1,j=cur-1;i>=0,j>=0;i--,row--){
      if(m[i][j]==1){
        return false;
      }
    }

    for(int i=row-1;i>=0;i--){
      if(m[i][cur]==1){
        return false;
      }
    }
    for(int i=row-1,j=cur+1;i>=0,j>=0;i++,row--){
      if(m[i][j]==1){
        return false;
      }
    }
    return true;
}

void printNQueens(int **m,int row,int size,string ans){
  if(row==size){
    cout<<ans+'.'<<endl;
  }

  for(int i=0;i<size;i++){
    m[row][i]=1;
    if(safesequence(m,row,i,size)){
    printNQueens(m,row+1,size,to_string(row) +'-'+to_string(i)+", ");
    }
    m[row][i]=0;
  }
}

int main(){
  int n;
  cin>>n;
  int **m=new int*[n];
  for(int i=0;i<n;i++){
    m[i]=new int[n];
    for(int j=0;j<n;j++){
      m[i][j]=0;
    }
  }
  printNQueens(m,0,n,"");
}
