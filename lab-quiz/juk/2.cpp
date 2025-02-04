#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int A[1000];
    for(int i = 0 ; i<n;i++){
        cin>>A[i];
    }

    int maxval = 0;

    
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = i ; j<n ;j++){
            sum = sum + A[j];
            if(sum>maxval){
                maxval = sum;
            }
        }
    }

    cout<<maxval;


    return 0;
}