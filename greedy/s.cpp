#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Job {
    int s, f;
};


bool comp(Job x, Job y) {
    return x.s < y.s;
}

int main() {
    int n;
    cin >> n;
    Job arr[n];  

   
    for (int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].f;
    }

    
    sort(arr, arr + n, comp);

    int machine[n] = {0};  
    int M = 0;  

    
    for (int i = 0; i < n; i++) {
        bool assigned = false;

       
        for (int j = 0; j < M; j++) {
            if (machine[j] <= arr[i].s) {  
                machine[j] = arr[i].f; 
                assigned = true;
                break;
            }
        }

        
        if (!assigned) {
            machine[M] = arr[i].f;
            M++;
        }
    }

    
    cout << "จำนวนเครื่องจักรขั้นต่ำที่ต้องใช้: " << M << endl;

    return 0;
}
