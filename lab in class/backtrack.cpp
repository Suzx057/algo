#include <stdio.h>
#include<iostream>
using namespace std;
//boy 1 == 1 girl2 == 2
//b1,g1,g2
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int X[], int start, int end) {
    
 
    if (start == end) {
//    	if(X[1] + X[2] ==5 || X[2] + X[3] == 5){
//    		return;
//		}
		if(X[1] == 1 || X[3] == 1){
			return;
		}
        for (int i = 1; i <= end; i++) {
            cout<<X[i]<<" ";
           
        }
        cout<<endl;
        //printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&X[start], &X[i]);
        permute(X, start + 1, end);
        swap(&X[start], &X[i]);
    }
}

int main() {
    int n = 3;
    //int X[] = {-1, 1, 2, 3};
    int b1  = 1;
    int g1  = 2;
    int g2  = 3;
    int X[] = {-1,b1,g1,g2};
    

    permute(X, 1, n);

    return 0;
}
