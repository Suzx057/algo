#include<iostream>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    int A[1000];
    for(int i = 0;i<n;i++){
        cin>>A[i];
    }
    int count = 0;
    for(int i = 0 ; i< n ;i++){
        for(int j = i + 1 ; j<n;j++){
            if(A[i] +A[j] == k){
                cout<<A[i]<<" "<<A[j]<<endl;
                count++;
            }
        }
    }
    if(count == 0){
        cout<<"-1";
    }
    return 0;
}