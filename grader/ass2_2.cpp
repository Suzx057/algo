#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // สำหรับ abs()
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // จำนวนสมาชิกของอาร์เรย์ และค่าผลรวมเป้าหมาย
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // รับค่าของอาร์เรย์
    }

    // กำหนดค่าที่ใหญ่มากแทน INT_MAX
    const int MAX_VALUE = 2147483647;

    // จัดเรียงอาร์เรย์
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    int closestDiff = MAX_VALUE; // ผลต่างที่น้อยที่สุด
    int bestPair[2] = {0, 0}; // คู่ที่ดีที่สุด

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            int diff = abs(arr[left] - arr[right]);
            if (diff < closestDiff) {
                closestDiff = diff;
                bestPair[0] = arr[left];
                bestPair[1] = arr[right];
            }
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    // แสดงผลลัพธ์
    if (closestDiff == MAX_VALUE) {
        cout << -1 << endl; // กรณีที่ไม่มีคู่ใดที่ผลรวมเท่ากับ K
    } else {
        cout << closestDiff << endl;
    }

    return 0;
}
