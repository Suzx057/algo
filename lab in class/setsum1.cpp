#include<iostream>
using namespace std;

int k;

void print_sol(int A[], int x[], int n) {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            cout << A[i] << " ";
        }
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
      	cout << x[i] << " ";
    }
   
}

// Function to check the subset sum
void subset1(int A[], int x[], int l, int r, int sum) {
    if (l == r) {
        // If the sum of the subset equals 36, print that subset
        if (sum == k) {
            print_sol(A, x, r);
        }
    } else {
        // Include the element A[l]
        x[l + 1] = 1;
        subset1(A, x, l + 1, r, sum + A[l + 1]);
        
        // Exclude the element A[l]
        x[l + 1] = 0;
        subset1(A, x, l + 1, r, sum);
    }
}
 
int main() {
    int n; // Number of elements in A
//    cin >> n >> k;
    cout<<"number of array: ";
    cin>>n;
    cout<<"number of sum: ";
    cin>>k;
    int x[n + 1]; // Array to store the selection status of each element
    int A[n + 1]; // Array to store the elements of the set

    cout << "Enter array : ";
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    subset1(A, x, 0, n, 0);

    return 0;
}

