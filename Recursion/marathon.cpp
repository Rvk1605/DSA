#include <iostream>
using namespace std;
void check(){
  int G,P;
  cin>>G>>P;
  int arr[10];
  for(int i=0;i<10;i++){
    cin>>arr[i];
  }
  int sum=0;
  int before_sum=0;

  for(int i=9;i>=G;i++){
    sum+=arr[i];
  }

  for(int i=9;i>=G+1;i++){
    before_sum+=arr[i];
  }



}
int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    check();
  }
}
