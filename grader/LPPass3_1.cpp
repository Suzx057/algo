#include <iostream>
#include <vector>

using namespace std;

// Function to perform Shell Sort and print the array after each pass
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // ใช้ gaps ตามโจทย์ต้องการ {4, 2, 1}
    int gaps[] = {4, 2, 1};  
    int num_gaps = sizeof(gaps) / sizeof(gaps[0]);

    for (int g = 0; g < num_gaps; g++) {
        int gap = gaps[g];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        
        // ✅ แสดงผลลัพธ์ที่ถูกต้องหลังจากทุก pass
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;  // อ่านขนาดของอาร์เรย์

    vector<int> arr(n);  // สร้างอาร์เรย์ขนาด n
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ✅ พิมพ์อาร์เรย์ก่อนเรียง
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shellSort(arr);

    return 0;
}
