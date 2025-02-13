#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

struct Object {
    int id;
    int profit;
    int weight;
    double avg;
};


bool comp(struct Object x, struct Object y) {
    return x.avg > y.avg;  
}

bool idd(struct Object x , struct Object y){
    return x.id<y.id;
}

bool pro(struct Object x , struct Object y){
    return x.profit>y.profit;
}

int main() {
    int n, w;
    cin >> n >> w;
    struct Object arr[n];

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].profit;
    }

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].weight;
    }

    
    for (int i = 0; i < n; i++) {
        arr[i].avg = (double)arr[i].profit / arr[i].weight;
        arr[i].id = i + 1;
    }

    
    sort(arr, arr + n, comp);
    sort(arr,arr+n,pro);

    int curr = 0;  
   

    
    for (int i = 0; i < n; i++) {
        if (curr + arr[i].weight <= w) {  
            curr += arr[i].weight;
            
            cout <<arr[i].profit << " " << arr[i].weight << endl;
        }
    }

   

    return 0;
}