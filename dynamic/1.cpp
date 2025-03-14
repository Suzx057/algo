#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXSIZE 20


int fac(int N) {
    if (N == 0) return 1;
    return N * fac(N - 1);
}

// Memoization array for Fibonacci
int memo[MAXSIZE];

// Bottom-Up DP for Fibonacci
int BottomUpDP_Fibo(int N) {
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= N; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[N];
}


int Fibo(int N) {
    if (N < 2) return N;
    return Fibo(N - 1) + Fibo(N - 2);
}

// Top-Down DP for Fibonacci
int TopDownDP_Fibo(int N) {
    if (memo[N] != -1) return memo[N]; // Check memo

    if (N < 2) {
        memo[N] = N;
    } else {
        memo[N] = TopDownDP_Fibo(N - 1) + TopDownDP_Fibo(N - 2);
    }
    return memo[N];
}

// Memoization for V function
int memo2[MAXSIZE][MAXSIZE];

// Recursive function V with DP
int V(int M, int N, vector<vector<int>>& A) {
    if (M == 0 || N == 0) return 0;
    return A[M][N] + max(V(M - 1, N, A), V(M - 1, N - 1, A));
}

// Bottom-Up DP for V function
int bottomUpDP_V(int M, int N, vector<vector<int>>& A) {
    vector<vector<int>> memo2(M + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            memo2[i][j] = A[i][j] + max(memo2[i - 1][j], memo2[i - 1][j - 1]);
        }
    }
    return memo2[M][N];
}

// Top-Down DP for V function
int topDownDP_V(int M, int N, vector<vector<int>>& A) {
    if (memo2[M][N] != -1) return memo2[M][N]; // Check memo

    if (M == 0 || N == 0) {
        memo2[M][N] = 0;
    } else {
        memo2[M][N] = A[M][N] + max(topDownDP_V(M - 1, N, A), topDownDP_V(M - 1, N - 1, A));
    }
    return memo2[M][N];
}

// Main function
int main() {
    // Initialize memoization table
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++)
            memo2[i][j] = -1;

    int M, N;
    cout << "Enter M, N: ";
    cin >> M >> N;

    vector<vector<int>> A(M + 1, vector<int>(N + 1, 0));

    // Read matrix A
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Result using Recursive V: " << V(M, N, A) << endl;
    cout << "Result using Bottom-Up DP: " << bottomUpDP_V(M, N, A) << endl;
    cout << "Result using Top-Down DP: " << topDownDP_V(M, N, A) << endl;

    return 0;
}