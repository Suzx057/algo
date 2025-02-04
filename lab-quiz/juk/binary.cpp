#include<iostream>
using namespace std;


int binary_search(int ar[], int find,int l,int r){
    if(r<l){//basecase
        return -1;
    }else{
        int mid = (l+r)/2;
        if(ar[mid] == find){
            return mid;
        }else if(ar[mid] < find){//cut left
            return binary_search(ar,find,mid+1,r);
        }else{  //cut right
            return binary_search(ar,find,l,mid-1);
        }
    }
}




int main(){
    int ar[] = {1,2,3,4,5};
    int a;
    cin >> a;
    cout<< "index : "<<binary_search(ar,a,0,4);
    return 0;
}