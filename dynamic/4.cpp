#include <iostream>
#include <vector>
using namespace std;

vector<int> A;  
vector<vector<int> > memo; // Memo


int V(int i, int j) {
    if (i > j) return 0; // เงื่อนไขที่ให้แสดง '.'
    if (i == j) return A[i]; //  V(i, i) = A(i)
    if (memo[i][j] != -1) return memo[i][j]; //  Memo
    
    // คำนวณค่าตามสมการที่กำหนด
    memo[i][j] = max(V(i + 1, j), V(i, j - 1)) + A[j];
    return memo[i][j];
}

int main() {
    int N;
    cin >> N;  
    
    A.resize(N + 1, 0);
    memo.resize(N + 1, vector<int>(N + 1, -1));
    
  
    for (int j = 1; j <= N; j++) {
        cin >> A[j];
    }
    
    
    V(1, N);
    
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i > j) {
                cout << ". "; 
            } else {
                cout << memo[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
