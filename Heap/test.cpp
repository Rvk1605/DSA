#include<iostream>
using namespace std;
void selection(int arr[],int n);
int main(){
    int arr[]={1,2,3,4,4,5,52,5,45};
    selection(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }
}