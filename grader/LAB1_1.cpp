#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countConsecutiveSubarrays(vector<int>& arr) {
    if (arr.empty()) return 0; // กรณีไม่มีข้อมูล

    sort(arr.begin(), arr.end()); // เรียงลำดับอาร์เรย์ (O(n log n))

    int count = 1; // เริ่มต้นด้วย 1 กลุ่ม
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1] + 1) { // ถ้าไม่ต่อเนื่องกัน นับเป็นกลุ่มใหม่
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n; // อ่านจำนวนสมาชิกของอาร์เรย์
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // รับค่าของอาร์เรย์
    }

    cout << countConsecutiveSubarrays(arr) << endl; // แสดงจำนวนกลุ่ม
    return 0;
}
