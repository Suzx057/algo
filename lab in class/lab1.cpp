#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector< vector <int> > matrix(m, vector<int>(m, 0)); 
    
    for (int i = 0; i < n; i++) {
        int row, col;
        cin >> row >> col;
        matrix[row][col] = 1; 
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
