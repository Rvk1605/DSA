#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n){
for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
        if(i*i==n){
            c++;
        else
            c+=2;
        }
    }
}
if(c==2)
    return true;
else
    return false;
}

long long strange_sum (int L, int R) {
   // Write your code here
   int sum=0;
   for(int i=L;i<=R;i++){
    for(int j=1;j<=i;i++){
        if(i%j==0&&j==1){
            sum+=0;
        }
        else if(i%j==0&&check_prime(j)==true){
            sum+=1;
        }

    }
   }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int L;
        cin >> L;
        int R;
        cin >> R;

        long long out_;
        out_ = strange_sum(L, R);
        cout << out_;
        cout << "\n";
    }
}
