#include <iostream>
using namespace std;

int J(int n){
	if(n == 0 || n == 1){
		return 0;
	}
	return J(n - 1) + J(n - 2) + 1;
}


int main(){
	
	int n;
	cout<<"Enter : ";
	cin>>n;
	cout<<"J(" << n << ") = " << J(n) << endl;
	
	return 0;
}
