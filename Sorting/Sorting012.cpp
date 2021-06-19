#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort_01(vector<int> &arr){
    int i=0,j=0;
    int pivot=1;
    while(i<arr.size()){
        if(arr[i]>pivot){
            i++;
        }
        else{
            swap(arr,i,j);
            i++;
            j++;
        }
    }
}

void sort_12(vector<int> &arr){
    return;
}

void sort012(vector<int> &arr)
{
    sort_01(arr);
    for(int i=0;i<arr.size();i++){
      cout<<arr[i]<<" ";
    }
    sort_12(arr);
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);
    sort012(A);
    print(A);
    return 0;
}
