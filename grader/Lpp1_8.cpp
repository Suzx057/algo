#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // จำนวนสมาชิกในอาร์เรย์
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // รับค่าในอาร์เรย์
    }

    int maxSum = -1000000; // ค่าเริ่มต้นของผลรวมสูงสุด
    for (int i = 0; i < n; i++) { // เริ่มต้นที่ตำแหน่ง i
        for (int j = i; j < n; j++) { // สิ้นสุดที่ตำแหน่ง j
            int currentSum = 0;
            for (int k = i; k <= j; k++) { // คำนวณผลรวมของลำดับ i ถึง j
                currentSum += arr[k];
            }
            maxSum = max(maxSum, currentSum); // อัปเดตผลรวมสูงสุด
        }
    }

    cout << maxSum << endl; // แสดงผลลัพธ์
    return 0;
}
