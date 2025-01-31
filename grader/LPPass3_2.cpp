#include <iostream>
#include <vector>

using namespace std;

// ฟังก์ชันสำหรับสร้าง Sedgewick's Sequence
vector<int> sedgewickSequence(int n) {
    vector<int> gaps;
    int k = 0;
    int gap;
    
    while (true) {
        if (k % 2 == 0)
            gap = 9 * (1 << (2 * k)) - 9 * (1 << k) + 1;
        else
            gap = (1 << (2 * k + 1)) - 3 * (1 << (k + 1)) + 1;
        
        if (gap >= n) break;
        gaps.push_back(gap);
        k++;
    }

    return gaps;
}

// ฟังก์ชัน Shell Sort โดยใช้ Sedgewick’s Sequence
void shellSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> gaps = sedgewickSequence(n);
    
    // เรียงลำดับ gaps ในลำดับจากมากไปน้อย
    for (int i = gaps.size() - 1; i >= 0; i--) {
        int gap = gaps[i];
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int k;
            for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
                arr[k] = arr[k - gap];
            }
            arr[k] = temp;
        }

        // แสดงผลหลังจากแต่ละรอบของการเรียงลำดับ
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n; // รับค่าจำนวนตัวเลขในอาร์เรย์
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // รับค่าข้อมูลในอาร์เรย์
    }

    // แสดงค่าเริ่มต้น
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(arr);

    return 0;
}