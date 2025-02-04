#include<iostream>
using namespace std;


int fac(int n){
    cout<< n << "\n";
    if(n == 1){
        return 1;
    }
    int a = n * fac(n -1);
    cout<< a << "\n";

    return a;
}

int main(){

   fac(5);

    


    return 0;
}