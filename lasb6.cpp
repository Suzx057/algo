#include <iostream>
using namespace std;


int Recursive(int x){
	if(x == 0){
		return 1;
		
	}
	return Recursive(x - 1) + 1;
}



int main(){
	int x;
	cout<<"Enter : ";
	cin>>x;
	cout<< "H(" << x << ") = " << Recursive(x) <<endl;
	return 0;
}
