#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชัน Interpolation Search แบบ Recursive
void interpolationSearchRecursive(vector<int>& arr, int low, int high, int target, vector<int>& mids) {
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));
        mids.push_back(pos);

        if (arr[pos] == target) {
            return; // เจอเป้าหมาย
        } else if (arr[pos] < target) {
            interpolationSearchRecursive(arr, pos + 1, high, target, mids);
        } else {
            interpolationSearchRecursive(arr, low, pos - 1, target, mids);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k; // จำนวนสมาชิกในอาร์เรย์ และค่าเป้าหมาย
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // รับค่าของอาร์เรย์
    }

    vector<int> mids; // เก็บตำแหน่ง mid ที่ใช้เปรียบเทียบ
    interpolationSearchRecursive(arr, 0, n - 1, k, mids);

    // แสดงผลลัพธ์
    for (int mid : mids) {
        cout << mid << " ";
    }
    cout << endl;

    return 0;
}
