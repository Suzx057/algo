#include<iostream>
using namespace std;

int main(){
	
	int m,n;
	cin>>m>>n;
	
	
	int arr[m][n];
	int x = 1;
	



	for(int i = 0 ;i<m;i++){
		if(i % 2 == 0){
			for(int j = 0 ; j<n;j++){
				arr[i][j] = x++;
						
		}
			
		}else if(i % 2 == 1){
			for(int j = n-1 ; j>=0 ;j--){
				arr[i][j] = x++;
				
			}
		}
		
	}	





//	for(int i = 0 ;i<m;i=i+2){
//		
//			for(int j = 0 ; j<n;j++){
//				arr[i][j] = x++;
//			}		
//		}		
//	for(int i =1; i<m;i=i+2){
//		for(int j = n-1 ; j>=0 ;j--){
//				arr[i][j] = x++;
//	}
//	
//	
	
		
//	}	


	
	
	
	
	for(int i =0;i<m;i++){
		for(int j = 0 ;j<n;j++){
			cout<<arr[i][j]<< " ";
		}
		cout<<endl;
	}
	
	
	
	
	
	return 0;
}
