#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x = 1;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(j<i){
                cout<<"0";
            }else{
                cout<<x;
                x++;
            }
        }
        cout<<endl;
    }
}