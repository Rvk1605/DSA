#include<iostream>
using namespace std;
int main(){
    int n;
     cin>>n;
     int a[n][3];
     for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
     }
     int fred=0,fgreen=0,fblue=0,sum=0,m;
     for(int i=0;i<n;i++){
        if(i==0){
            m=min(a[i][0],min(a[i][1],a[i][2]));
            if(m==a[i][0]){
                fred=1;
            }
            else if(m==a[i][1])
                fblue=1;
            else
                fgreen=1;
        }
        else{
            if(fred==1&&fgreen==0&&fblue==0){
                m=min(a[i][1],a[i][2]);
                fred=0;
                if(m==a[i][1])
                    fblue=1;
                else
                    fgreen=1;
            }
            else if(fred==0&&fblue==1&&fgreen==0){
                m=min(a[i][0],a[i][2]);
                fblue=0;
                if(m==a[i][0])
                    fred=1;
                else
                    fgreen=1;
            }
            else if(fred==0&&fblue==0&&fgreen==1){
                m=min(a[i][0],a[i][1]);
                fgreen=0;
                if(m==a[i][0])
                    fred=1;
                else
                    fblue=1;
            }
        }
        sum+=m;
     }
     cout<<sum;

}
