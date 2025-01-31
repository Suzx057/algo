#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชันตรวจสอบแบบ Recursive
bool isSortedRecursive(const vector<int>& arr, int index) {
    if (index == arr.size() - 1) // กรณี base case: ถ้าถึงตัวสุดท้าย ถือว่า sorted
        return true;
    if (arr[index] > arr[index + 1]) // ถ้าพบว่าค่าก่อนหน้า > ค่าถัดไป แสดงว่าไม่เรียง
        return false;
    return isSortedRecursive(arr, index + 1); // เรียกฟังก์ชันต่อไป
}

int main() {
    int n;
    cin >> n;  // อ่านค่าขนาดของอาร์เรย์

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // เรียกฟังก์ชัน recursive และพิมพ์ Yes หรือ No
    if (isSortedRecursive(arr, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
