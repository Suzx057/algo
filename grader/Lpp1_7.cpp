#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; // อ่านค่าจำนวนสมาชิกของอาร์เรย์และค่าเป้าหมาย
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // อ่านค่าของอาร์เรย์
    }

    bool found = false; // ตัวแปรเพื่อตรวจสอบว่าพบคู่หรือไม่

    // ใช้ลูป 2 ชั้นเพื่อตรวจสอบคู่ของจำนวนที่ผลรวมเท่ากับ k
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                cout << arr[i] << " " << arr[j] << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << -1 << endl; // หากไม่พบคู่ใดที่ผลรวมเท่ากับ k
    }

    return 0;
}
