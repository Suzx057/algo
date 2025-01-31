#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n; // อ่านจำนวนสมาชิกในอาร์เรย์

    unordered_set<int> uniqueValues; // ใช้ unordered_set เพื่อเก็บค่าที่ไม่ซ้ำกัน

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        uniqueValues.insert(num); // เพิ่มค่าเข้า set
    }

    cout << uniqueValues.size() << endl; // จำนวนค่าที่แตกต่างกันในอาร์เรย์
    return 0;
}
