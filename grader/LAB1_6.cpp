#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1. เรียงลำดับอาร์เรย์ O(n log n)
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int best_i = -1, best_j = -1;
    int min_diff = numeric_limits<int>::max();

    // 2. ใช้ Two-Pointer O(n)
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == k) { 
            int diff = abs(arr[right] - arr[left]); // คำนวณผลต่าง
            if (diff < min_diff) { 
                min_diff = diff;
                best_i = arr[left];
                best_j = arr[right];
            }
            left++;  // ขยับ pointer เพื่อหาคู่ที่ดีกว่า
            right--; // ลดขนาดช่วงให้แคบลง
        } else if (sum < k) {
            left++; // ถ้าผลรวมยังน้อยไป ให้เพิ่ม left
        } else {
            right--; // ถ้าผลรวมมากไป ให้ลด right
        }
    }

    // 3. แสดงผลลัพธ์ ถ้าพบคู่ที่ใช่
    if (best_i != -1 && best_j != -1) {
        cout << best_i << " " << best_j << endl;
    }

    return 0;
}
