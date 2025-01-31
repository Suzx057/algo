#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int time;
    int type; // +1 สำหรับเข้า, -1 สำหรับออก
};

bool compare(const Event &a, const Event &b) {
    if (a.time == b.time) 
        return a.type < b.type; // ให้ +1 มาก่อน -1 ถ้าเวลาตรงกัน
    return a.time < b.time;
}

int main() {
    int n;
    cin >> n;

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int entry;
        cin >> entry;
        events.push_back({entry, +1});
    }

    for (int i = 0; i < n; i++) {
        int exit;
        cin >> exit;
        events.push_back({exit, -1});
    }

    sort(events.begin(), events.end(), compare);

    int current_students = 0, max_students = 0;
    int start_time = 0, end_time = 0;
    bool tracking = false;

    for (const auto &event : events) {
        current_students += event.type;

        if (current_students > max_students) {
            max_students = current_students;
            start_time = event.time;
            end_time = event.time;
            tracking = true;
        } else if (current_students == max_students && tracking) {
            end_time = event.time;
        } else if (current_students < max_students) {
            tracking = false;
        }
    }

    cout << start_time << " " << end_time << " " << max_students << endl;
    return 0;
}
