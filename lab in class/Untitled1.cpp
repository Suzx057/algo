#include<iostream>
using namespace std;

int main(){
	
	int m,n;
	cin>>m>>n;
	
	int arr[m][n];
	
	int x = 1;
	//row2 col1
//	for(int i = m ; m>=0 ;i--){
//		for(int j = n ; n>=0 ;j--){
//			arr[i][j] = 0;
//		}
//	}
//	

	for(int i = m-1; i>=0 ;i--){
		for(int j = n-1 ; j>=0 ; j--){
			arr[i][j] = x++;
		}
	}


	for(int i = 0; i<m ; i++){
		for(int j = 0 ;j<n ; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
