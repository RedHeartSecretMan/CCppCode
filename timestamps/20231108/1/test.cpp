#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int> &arr, int low, int high);

int main() {
    int n = 0;// number of elements in the array
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);// create a vector (dynamic array) of size n
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print the original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int less = low + 1;
        int greater = high;
        while (true) {
            while (less <= greater && arr[less] <= pivot)
                less++;
            while (less <= greater && arr[greater] > pivot)
                greater--;
            if (less <= greater)
                swap(arr[less], arr[greater]);
            else
                break;
        }
        swap(arr[low], arr[greater]);
        quicksort(arr, low, greater - 1);
        quicksort(arr, greater + 1, high);
    }
}
