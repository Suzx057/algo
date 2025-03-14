#include <iostream>
using namespace std;

int M, N;
int A[100][100]; 
int V[100][100]; 


int calv(int m, int n) {
    if (m < 0 || n < 0) return 0; 
    if (V[m][n] != -1) return V[m][n]; 

    int prev1 = calv(m - 1, n);
    int prev2 = calv(m - 1, n - 1);
    int maxprev;

    
    if (prev1 > prev2) {
        maxprev = prev1;
    } else {
        maxprev = prev2;
    }

    V[m][n] = A[m][n] + maxprev; 
    return V[m][n];
}

int main() {
    cin >> M >> N;

    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            V[i][j] = -1; 
        }
    }
	cout<<endl;
	cout<<"output "<<endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << calv(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
