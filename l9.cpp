#include <iostream>
using namespace std;

double P(double x,int n){
	if(n == 0){
		return 1.0;
	}
	if(n > 0){
		return x * P(x,n - 1);	
	}else{
		return 1.0 / P(x, -n);
	}
	
}

int main(){
	double x;
	int n;
	cout<<"Base(x) : " ;
	cin>>x;
	cout<<"(n) : ";
	cin>>n;
	
	cout<<"p: "<< P(x,n);
	
	return 0;
	
}
