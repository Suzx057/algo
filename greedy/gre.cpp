#include<iostream>
using namespace std;
#define TYPES 9

int main(){
    int n;
    int coin[TYPES] = {1,2,5,10,20,50,100,500,1000};
    int result[TYPES] = {0};
    cout<<"จำนวณบาท : ";
    cin>>n;
    //คำนวณ

     
    for(int i = TYPES-1;i>=0;i--){
        result[i] = n/coin[i];
        n = n - coin[i] * result[i];
    }



    
    for(int i = TYPES-1;i>=0;i--){
        if(coin[i] * result[i] != 0){
            cout<<coin[i]<<" บาท "<<" * "<<result[i]<<" ใบ "<<" = "<<coin[i] * result[i]<<endl;
        }
        
    }
    return 0;
}