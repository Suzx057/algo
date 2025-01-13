#include <iostream>
using namespace std;

int main(){

    int m,n;
    cin>>m>>n;

    int arr[m][n];
    int x = 1;

    for(int j = 0 ; j<n ; j++){
        for(int i = 0 ; i<m ; i++){
            arr[i][j] =x++;
        }
    }



    for(int i = 0 ; i<m;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}