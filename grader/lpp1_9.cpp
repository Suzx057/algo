#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int count = 0;

    while(n>0){
        if( n % 2 == 1) count++; 
        //cout<<"ขอดู"<<n<<"count "<<count<<endl;
        n = n >> 1; //shift right คือการ หาร ex. 15 >> 1 == 7 , 15 >> 2 == 3

    }
        
    
   

    cout<<count;


    return 0;
}