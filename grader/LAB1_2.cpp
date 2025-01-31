#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n; // จำนวนข้อมูล
    unordered_map<int, int> freq; // เก็บความถี่ของตัวเลขแต่ละตัว

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freq[num]++; // เพิ่มค่าความถี่ของตัวเลข
    }

    int maxFreq = 0, minFreq = n;
    
    // หาค่าความถี่สูงสุดและต่ำสุด
    for (const auto& entry : freq) {
        maxFreq = max(maxFreq, entry.second);
        minFreq = min(minFreq, entry.second);
    }

    cout << maxFreq - minFreq << endl; // แสดงผลลัพธ์
    return 0;
}
