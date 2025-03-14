#include <iostream>
using namespace std;

int N;
int A[100];  
int V[100][100];  // Memoization table

int calv(int n, int i, int j) {
    if (i > j) return 0;  
    if (i == j) return A[i];  
    if (V[i][j] != -1) return V[i][j];  

    
    if (n == 0) return 0;  

    
    V[i][j] = max(A[i] + calv(n - 1, i + 1, j), A[j] + calv(n - 1, i, j - 1));
    return V[i][j];
}

int main() {
    cin >> N;
    
    for (int j = 0; j < N; j++) {  
        cin >> A[j];
    }
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            V[i][j] = -1;
        }
    }
    
    
    calv(N, 0, N - 1);

    
    cout << endl << "Output:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                cout << ". "; 
            } else {
                cout << V[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
