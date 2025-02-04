#include<iostream>
using namespace std;

void merge(int arr[] ,int left,int mid,int right){
    int n1 = mid - left + 1 , n2 = right - mid;
    int L[n1] , R[n2];

    for(int i = 0;i<n1;i++){
        L[i] = arr[left + i];
    }
    for(int i = 0;i<n2;i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0,j=0,k=left;
    while(i<n1&&j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++] = L[i++];
    }
    while(i<n2){
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid = left + (right - left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int bina(int arr[] , int left,int right,int target){
    if(left>right){
        return -1;
    }

    int mid = left + (right - left)/2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] < target){
        return bina(arr,mid+1,right,target);
    }else{
        return bina(arr,left,mid-1,target);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[1000];

    for(int i = 0 ; i<n ;i++){
        cin>>arr[i];
    }

    mergesort(arr,0,n-1);
    for(int i = 0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }


    int target;
    cout<<endl<<"Enter : ";
    cin>>target;
    int result = bina(arr,0,n,target);

    if(result != -1){
        cout<<"target ที่ : "<<target<<" อยู่ที่ index : "<<result;
    }else{
        cout<<"-1";
    }
}