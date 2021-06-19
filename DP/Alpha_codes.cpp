#include<bits/stdc++.h>
using namespace std;

int find_no_codes(vector<int> v1,int n){
if(n==0||n==1)
    return 1;
int c=find_no_codes(v1,n-1);
if(v1[n-2]*10+v1[n-1]<26)
    c=c+find_no_codes(v1,n-2);
return c;

}

vector <int> get_array(long long int n){
    vector <int> ans;
    while(n!=0){
        int r=n%10;
        ans.push_back(r);
        n=n/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
 int main(){
    int t;
    cin>>t;
     for(int i=0;i<t;i++){
        long long int n;
        cin>>n;
        vector <int> arr=get_array(n);
        int len=arr.size();
        cout<<"\n"<<find_no_codes(arr,len)<<endl;
    }
 }
