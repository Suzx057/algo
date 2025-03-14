#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 100

int N, W;
int value[MAX_N + 1], weight[MAX_N + 1]; // ค่า v_i และน้ำหนัก w_i (เริ่ม index 1)
int memo[MAX_N + 1][MAX_W + 1]; // ตาราง Memoization

// ฟังก์ชัน Top-down DP (Memoization)
int knapsackTopDown(int i, int w) {
    if (i == 0 || w == 0) return 0; // Base case
    if (memo[i][w] != -1) return memo[i][w]; // ใช้ค่าที่คำนวณไว้แล้ว

    if (weight[i] > w) {
        memo[i][w] = knapsackTopDown(i - 1, w); // ไอเท็มหนักเกินไป
    } else {
        memo[i][w] = max(knapsackTopDown(i - 1, w), value[i] + knapsackTopDown(i - 1, w - weight[i]));
    }
    return memo[i][w];
}

void printMemo() {
    cout << "\nTop-down DP Memory Table:\n";
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            cout << (memo[i][w] == -1 ? 0 : memo[i][w]) << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> N >> W; // รับจำนวน items และน้ำหนักสูงสุด
    for (int i = 1; i <= N; i++) {
        cin >> value[i] >> weight[i]; // รับค่า value และ weight
    }

    // กำหนดค่าเริ่มต้นของ Memoization เป็น -1
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            memo[i][w] = -1;
        }
    }

    int maxValue = knapsackTopDown(N, W);
    printMemo();

    cout << "\nMaximum value (Top-down DP): " << maxValue << endl;
    return 0;
}
