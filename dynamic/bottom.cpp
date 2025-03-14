#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 100

int N, W;
int value[MAX_N + 1], weight[MAX_N + 1]; 
int memo[MAX_N + 1][MAX_W + 1]; 

// Bottom-up DP
int knapsackBottomUp() {
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                memo[i][w] = 0;  
            } else if (weight[i] > w) {
                memo[i][w] = memo[i - 1][w];  
            } else {
                memo[i][w] = max(memo[i - 1][w], value[i] + memo[i - 1][w - weight[i]]);
            }
        }
    }
    return memo[N][W];
}


void resetMemo() {
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            memo[i][w] = -1; 
        }
    }
}

int knapsackTopDown(int i, int w) {
    if (i == 0 || w == 0) return 0; // Base case
    if (memo[i][w] != -1) return memo[i][w]; 

    if (weight[i] > w) {
        memo[i][w] = knapsackTopDown(i - 1, w); //หนักเกิน
    } else {
        memo[i][w] = max(knapsackTopDown(i - 1, w), value[i] + knapsackTopDown(i - 1, w - weight[i]));
    }
    return memo[i][w];
}


void printMemoBottomUp() {
    cout << "\nBottom-up DP Memory Table:\n";
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            cout << memo[i][w] << " ";
        }
        cout << endl;
    }
}


void printMemoTopDown() {
    cout << "\nTop-down DP Memory Table:\n";
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (memo[i][w] == -1) {
                cout << "0 "; 
            } else {
                cout << memo[i][w] << " "; 
            }
        }
        cout << endl;
    }
}


int main() {
    cin >> N >> W; 
    for (int i = 1; i <= N; i++) {
        cin >> value[i] >> weight[i]; 
    }

    
    int maxValue = knapsackBottomUp();
    printMemoBottomUp();
    cout << "\nMaximum value (Bottom-up DP): " << maxValue << endl;

    
    resetMemo();
    int maxValue1 = knapsackTopDown(N, W);
    printMemoTopDown();
    cout << "\nMaximum value (Top-down DP): " << maxValue1 << endl;

    return 0;
}


