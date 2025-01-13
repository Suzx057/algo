#include<iostream>
using namespace std;

int main(){
	
	int m,n;
	cin>>m>>n;
	
	int arr[m][n];
	int x = 1;
	
	for(int i = 0 ; i<m ;i++ ){
		if(i % 2 == 0){
			for(int j =0; j<n ;j++){
			arr[i][j] = x++;
			i++;
		}	
		
		}else if(i % 2 == 1){
			for(int j =0; j<n ;j++){
			arr[i][j] = x++;
			i++;
		}
		
	}
}
	
	
		
	for(int i = 0 ; i<m;i++ ){
		for(int j =0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
