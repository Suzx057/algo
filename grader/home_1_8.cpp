#include<iostream>
using namespace std;

int main(){
    int n; int A[1000];
    cin>>n;
    

    for(int i = 0 ; i<n ; i++){
        cin>>A[i];
    }

    int Maxvalue = A[0] , Maxstart=0, Maxstop=0;
    for(int i = 0 ; i<n ;i++){
        for(int sum = 0, j = i ; j<n ; j++){
            sum = sum+A[j];
            if(sum>Maxvalue) {
                Maxvalue = sum;
                Maxstart = i;
                Maxstop = j;
            }
        }
    }

    cout<<Maxvalue<<endl;
    for(int i = Maxstart;i<=Maxstop;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}