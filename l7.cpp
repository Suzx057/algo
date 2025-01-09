#include<iostream>
using namespace std;

int M(int n){
	if(n == 1){
		return 0;
	}
	return M(n / 2) + n;
}


int main(){
	int n ;
	cout<<"Enter : ";
	cin>>n;
	
	cout<<"M(" << n << ") = " << M(n) << endl;
	
	
	return 0;
}
