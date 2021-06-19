#include<iostream>
using namespace std;
int digit_count(int n){
if(n==0){
    return 0;
}
int c=0;
    while(n!=0){
        n=n/10;
        c++;
    }
    return c;
}

int sum_digits(int n){
    if(n==0){
    return 0;
    }
    int sum=0;
    for(int i=n;i!=0;i=i/10){
        int r=i%10;
        sum+=r;
    }
    return sum;
}

int main(){
int n;
cout<<"Enter a Number:";
cin>>n;

while(digit_count(n)!=1){
    n=sum_digits(n);
    cout<<"Sum of Digits :"<<n<<endl;
}
if(n%3==0)
    cout<<"Divisible By 3"<<endl;
else
    cout<<"Not Divisible By 3"<<endl;

}

