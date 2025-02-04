#include<iostream>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    int arr[1000];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 0 ; i<n; i++){
        for(int j = i + 1;j<n;j++){
            if(arr[i] + arr[j] == k){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }

}